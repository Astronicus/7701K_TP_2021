#include "main.h"

int liftVoltage = 127;
int lowerVoltage = -127;

void liftControl(){
  bool raiseLiftButton=master.get_digital(DIGITAL_L2);
  bool lowerLiftButton=master.get_digital(DIGITAL_L1);

  if(raiseLiftButton && lowerLiftButton){
    //do nothing
  }
  else if (raiseLiftButton){
    leftLift.move(liftVoltage);
    rightLift.move(liftVoltage);
  }
  else if (lowerLiftButton){
    leftLift.move(lowerVoltage);
    rightLift.move(lowerVoltage);
  }

}
