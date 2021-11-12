#include "main.h"

int liftVoltage = 127;
int lowerVoltage = -127;

void liftControl(){
  leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  
  bool raiseLiftButton=master.get_digital(DIGITAL_L2);
  bool lowerLiftButton=master.get_digital(DIGITAL_L1);

  if(raiseLiftButton && lowerLiftButton){
    leftLift.move(0);
    rightLift.move(0);
  }
  else if (raiseLiftButton){
    leftLift.move(liftVoltage);
    rightLift.move(liftVoltage);
  }
  else if (lowerLiftButton){
    leftLift.move(lowerVoltage);
    rightLift.move(lowerVoltage);
  }
  else{
    leftLift.move(0);
    rightLift.move(0);
  }

}
