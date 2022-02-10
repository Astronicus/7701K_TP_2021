#include "main.h"


//unsigned int auton_num{}; //global <--declared in main

void setupSelector(){
  //Auton Selector

  unsigned int count{};
  std::string autonNames[7]= {"Left","Right","LeftWinP","RightWinP","Skills","NeutralDist","DoNothing"};
  count=0; //defined in main.h

  while(true){
  	if(tapA.get_new_press() == 1) { //change count number when adding more
  		 count++;
  	}
    if(tapB.get_new_press() == 1){
      count--;
    }
    if(count>6){ //prefer to use array.length
  		count=0;
  	}

    pros::lcd::print(2,"%d: %s\n",count,autonNames[count]);

  	if(tapC.get_new_press() == 1){
  		auton_num=count;
  	  pros::lcd::print(2,"%d: %s \t Auton Chosen \n",count,autonNames[count]);
  	  break;
  	}
  	pros::delay(20);
	} // End autonSelector while statement
} // End if
