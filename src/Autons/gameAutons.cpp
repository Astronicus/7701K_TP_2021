#include "main.h"

void redFront(){
  chassis::move(54,100);
  chassis::turn(90,100);
}

void redBack(){
  chassis::move(54,100);
  chassis::turn(90,100);
}

void blueFront(){
  chassis::move(54,100);
  chassis::turn(90,100);
}

void blueBack(){
  chassis::move(54,100);
  chassis::turn(90,100);
}

void doNothing(){

}

void autonTest(){
  bool runAuton = master.get_digital(pros::E_CONTROLLER_DIGITAL_B);
  if(runAuton && !pros::competition::is_connected()){
    pros::delay(100);
    chassis::init({5,14},{16,19}, //leftdrive and rightdrive motors
  								200, //gearset
  								71, //ticks per unit travel
  								8.0, //ticks per degree
  								8, //settle time
  								3, //settle linear
  								1, //settle angular
  								2, 2, //regular/arc slew
  								0, //imu port (none)
  								{0,0,0}, //encoder ports
  								0, //expander port
  								5 //joystick threshhold
  	);
  	pid::init(false, //debug output
  						.3,0,.5, //pid values moving
  						.8,0,3, //pid values for turning
  						8,0,0, //linear point constants
  						50,0,0,//angular point constants
  						.05, //arc kp
  						0, //dif kp
  						3 //min error
  	 );
     pros::delay(200);
    chassis::move(54,100);
    chassis::turn(180,70);
    clampRotate(0.6,100);
    runAuton = false;
  }
}
