#include "main.h"

void leftAuton(){
  backBarDown(200);
	moveRel(-2.05,200);
  moveRel(-0.3,100);
	backBarUp(100);
	pros::delay(1000);
	moveRel(1.8,150);

}

void rightAuton(){
  backBarDown(200);
  /*moveRel(-2.05,125);
  pros::delay(500);
  backBarUp(100);
  pros::delay(1000);
  moveRel(1.8,150);
  */
}

void leftWPAuton(){
  piston1.set_value(false);
  piston2.set_value(false);

}

void rightWPAuton(){
  moveRel(-0.8,75);
  pros::delay(500);
  piston1.set_value(false);
  piston2.set_value(false);
  pros::delay(500);
  piston1.set_value(true);
  piston2.set_value(true);
  pros::delay(500);
  moveRel(0.7,75);
  pros::delay(500);
  backBarDown(200);
  pros::delay(1000);
  moveRel(-1.2,75);
  pros::delay(500);
  backBarUp(150);
  pros::delay(750);
  turnRel(35,50);
  pros::delay(500);
  moveRel(1.5,100);
  pros::delay(150);
  backBarDown(100);
  pros::delay(4000);

}

void skillsRun(){
  backBarDown(200);
  pros::delay(1000);
  moveRel(-4.3,100);
  pros::delay(1000);
  moveRel(0.8,100);
  pros::delay(1000);
  turnRel(50,100);
  pros::delay(1000);
  moveRel(3.8,100);
  pros::delay(1000);
  moveRel(-0.4,100);
  pros::delay(1000);
  turnRel(-50,80);
  pros::delay(1000);
  moveRel(-2.5,100);

}

void doNothing(){

}

void neutralDistAuton(){
  backBarDown(200);
	moveRel(-2.05,125);
	pros::delay(500);
	backBarUp(100);
	pros::delay(1000);
	moveRel(1.8,150);
}
