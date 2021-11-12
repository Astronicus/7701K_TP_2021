#include "main.h"

int intakeVoltage = 127;
int outtakeVoltage = -127;

void intakeControl(){
  bool intakeButton=master.get_digital(DIGITAL_R2);
  bool outtakeButton=master.get_digital(DIGITAL_R1);

  if(intakeButton && outtakeButton){
    conveyorMotor.move(0);
  }
  else if (intakeButton){
    conveyorMotor.move(intakeVoltage);
  }
  else if (outtakeButton){
    conveyorMotor.move(outtakeVoltage);
  }
  else{
    conveyorMotor.move(0);
  }

}
