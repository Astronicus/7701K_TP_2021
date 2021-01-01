#include "main.h"

int liftVoltage = 100;
int lowerVoltage = -100;

void liftControl(){
  leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  bool raiseLiftButton=master.get_digital(DIGITAL_L2);
  bool lowerLiftButton=master.get_digital(DIGITAL_L1);

  if(raiseLiftButton && lowerLiftButton){
    leftLift.move_velocity(0);
    rightLift.move_velocity(0);
  }
  else if (raiseLiftButton){
    leftLift.move_velocity(liftVoltage);
    rightLift.move_velocity(liftVoltage);
  }
  else if (lowerLiftButton){
    leftLift.move_velocity(lowerVoltage);
    rightLift.move_velocity(lowerVoltage);
  }
  else{
    leftLift.move_velocity(0);
    rightLift.move_velocity(0);
  }

}
