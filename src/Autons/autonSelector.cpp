#include "main.h"
int autonSize = 3;
void setupSelector(){
  //Auton Selector

  unsigned int count{};
  std::string autonNames[autonSize]= {"exampleAuton1", "exampleAuton2","exampleAuton3"};
  count=0; //defined in main.cpp

  while(true){
      if(tapA.get_new_press() == 1) { //change count number when adding more
           count++;
      }
    if(tapB.get_new_press() == 1){
      count--;
    }
    if(count>autonSize){ //prefer to use array.length
          count=3;
      }

    pros::lcd::print(2,"%d: %s\n",count,autonNames[count]);

      if(tapC.get_new_press() == 1){
          auton_num=count;
        pros::lcd::print(2,"%d: %s \t Auton Chosen \n",count,autonNames[count]);
        break;
      }
      pros::delay(20);
    } // End autonSelector while statement //
} //End Void
