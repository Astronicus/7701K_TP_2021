#include "main.h"

void hookControl(){
  bool closeHook = master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  bool openHook = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);

  if (closeHook){
    piston.set_value(true);
    pros::lcd::print(1,"true pressed");
  }
  else if(openHook){
    piston.set_value(false);
    pros::lcd::print(1,"false pressed");
  }


}

/*int hookVelocity = 150;

void hookControl(){
  hookMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  bool closeHook = master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  bool openHook = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);

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
*/
