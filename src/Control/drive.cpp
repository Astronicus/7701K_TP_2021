#include "main.h"


void brakeMode(){
  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

////////////////////////////////////////////////////////////////////////////////

void coastMode(){
  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void printDriveSpeeds(float fl, float fr, float bl, float br){
  pros::lcd::print(0,"FL: %f",fl);
  pros::lcd::print(1,"FR: %f",fr);
  pros::lcd::print(2,"BL: %f",bl);
  pros::lcd::print(3,"BR: %f",br);
}


////////////////////////////////////////////////////////////////////////////////

void driveControl() { //defining tank drive function
  //Arcade Drive
    //Setting up integers to represent motor speed via joysticks
  float LEFTY= master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  float RIGHTX= master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  //Linear multiply
  LEFTY = LEFTY * 1.27;
  if(LEFTY>127){
    LEFTY = 127;
  }

  //severity of turns
  //RIGHTX = RIGHTX * 5/6;

  //Deadzones
  if( (LEFTY < 5) && (LEFTY > -5) ){
    LEFTY=0;
  }
  if( (RIGHTX < 5) && (RIGHTX > -5) ){
    RIGHTX=0;
  }

  double turnConst = 1.5;       // lower = linear, higher = cubic; cannot be 0
  double turnInput = master.get_analog(ANALOG_RIGHT_X) * (double)105.0 / 127.0;
  double turnSpeed = turnConst * (pow(turnInput, 3) / 10000 + turnInput / turnConst) / (turnConst + 1);

  float frontLeftMod = (LEFTY + turnSpeed); //front left
  float frontRightMod = (LEFTY - turnSpeed); //front right
  float backLeftMod = (LEFTY + turnSpeed); //back left
  float backRightMod = (LEFTY - turnSpeed); //back right

  frontLeft.move (frontLeftMod ); // * driveMultiplier
  frontRight.move(frontRightMod );
  backLeft.move  (backLeftMod  );
  backRight.move (backRightMod  );

  //printDriveSpeeds(frntLftMod,frntRigMod,bckLftMod,bckRigMod);

  //https://www.vexforum.com/t/slowing-down-v5-motors/51787/2
  //https://www.vexforum.com/t/optimizing-exponential-drive/73719

} // Op Drive Ends//
