#include "main.h"

int hookVelocity = 150;

void hookControl(){
  hookMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  bool closeHook = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
  bool openHook = master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);

  if(closeHook && openHook){
    hookMotor.move_velocity(0);
  }
  else if (closeHook){
    hookMotor.move_velocity(hookVelocity);
  }
  else if (openHook){
    hookMotor.move_velocity(-hookVelocity);
  }
  else{
    hookMotor.move_velocity(0);
  }
}
