#include "main.h"

int clampVelocity = 100;

void clampControl(){
  clampMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  bool closeClamp = master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  bool openClamp = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);

  if(closeClamp && openClamp){
    clampMotor.move_velocity(0);
  }
  else if (closeClamp){
    clampMotor.move_velocity(clampVelocity);
  }
  else if (openClamp){
    clampMotor.move_velocity(-clampVelocity);
  }
  else{
    clampMotor.move_velocity(0);
  }
}
