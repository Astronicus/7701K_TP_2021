#include "main.h"

int intakeSpeed = 125;
int outtakeSpeed = -200;

void backFourBarControl(){
  backFourBarMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  bool intakeButton=master.get_digital(DIGITAL_R1);
  bool outtakeButton=master.get_digital(DIGITAL_R2);

  if(intakeButton && outtakeButton){
    backFourBarMotor.move(0);
  }
  else if (intakeButton){
    backFourBarMotor.move_velocity(intakeSpeed);
  }
  else if (outtakeButton){
    backFourBarMotor.move_velocity(outtakeSpeed);
  }
  else{
    backFourBarMotor.move(0);
  }

}
