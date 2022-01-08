#include "main.h"

int intakeVoltage = 127;
int outtakeVoltage = -127;

void backFourBarControl(){
  bool intakeButton=master.get_digital(DIGITAL_R1);
  bool outtakeButton=master.get_digital(DIGITAL_R2);

  if(intakeButton && outtakeButton){
    backFourBarMotor.move(0);
  }
  else if (intakeButton){
    backFourBarMotor.move(intakeVoltage);
  }
  else if (outtakeButton){
    backFourBarMotor.move(outtakeVoltage);
  }
  else{
    backFourBarMotor.move(0);
  }

}
