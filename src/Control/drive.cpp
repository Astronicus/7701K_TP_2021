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
  //Braking
  if (master.get_digital(DIGITAL_X)) { //When press button X, drive motors brake
    brakeMode();
  }
  //Arcade Drive
    //Setting up integers to represent motor speed via joysticks
  float LEFTY= master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  float RIGHTX= master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  //severity of turns
  int turn_multiplier = 0.75;
  RIGHTX *= turn_multiplier;

  //Deadzones
  if( (LEFTY < 5) && (LEFTY > -5) ){
    LEFTY=0;
  }
  if( (RIGHTX < 5) && (RIGHTX > -5) ){
    RIGHTX=0;
  }

  //Raw value summation
  // 2/3 rightX multiplier before
  /*
  if(fabs(LEFTY) < 20.0){
    RIGHTX *= (5.0 / 6);
  }
  */

  float frontLeftRaw = (LEFTY + RIGHTX); //front left
  float frontRightRaw = (LEFTY - RIGHTX); //front right
  float backLeftRaw = (LEFTY + RIGHTX); //back left
  float backRightRaw = (LEFTY - RIGHTX); //back right


  //Raw value modifier
  float frntLftMod = frontLeftRaw * pow((fabs(frontLeftRaw) / 127),1); //(pow(fabs(frntLftRaw),2) / 100)
  float frntRigMod = frontRightRaw * pow((fabs(frontRightRaw) / 127),1);
  float bckLftMod =  backLeftRaw  * pow((fabs(backLeftRaw)  / 127),1);
  float bckRigMod =  backRightRaw  * pow((fabs(backRightRaw)  / 127),1);

  frontLeft.move (frntLftMod ); // * driveMultiplier
  frontRight.move(frntRigMod );
  backLeft.move  (bckLftMod  );
  backRight.move (bckRigMod  );

  //printDriveSpeeds(frntLftMod,frntRigMod,bckLftMod,bckRigMod);

  //https://www.vexforum.com/t/slowing-down-v5-motors/51787/2
  //https://www.vexforum.com/t/optimizing-exponential-drive/73719

} // Op Drive Ends//
