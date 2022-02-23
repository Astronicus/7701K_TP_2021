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
	moveRel(-2.05,200);
  moveRel(-0.3,100);
	backBarUp(100);
	pros::delay(1000);
	moveRel(1.8,150);
}

void leftWPAuton(){
  piston1.set_value(true);
  piston2.set_value(true);
  pros::delay(1000);
  moveRel(0.3,100);
  turnRel(-50,100);
  backBarDown(200);
  moveRel(-2.6,175);
  moveRel(-0.6,100);
  backBarUp(100);
  pros::delay(450);
  moveRel(1.0,100);


}

void rightWPAuton(){
  moveRel(-0.8,75);
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
  moveRel(-0.25,100);
  moveRel(0.25,100);

}

void skillsRun(){
  //backBarDown(200);
  moveRel(-0.8,50);
  piston1.set_value(true);
  piston2.set_value(true);
  pros::delay(500);
  moveRel(-3.4,100);
  moveRel(0.5,100);
  //backBarUp(200);
  turnRel(42,100);
  moveRel(3.1,100);
  moveRel(-0.2,100);
  turnRel(-58,80);
  moveRel(-2.83,100);
  pros::delay(500);
  moveRel(0.2,100);
  pros::delay(500);
  turnRel(-77,80);
  pros::delay(500);
  backBarDown(200);
  pros::delay(1000);
  moveRel(-1.45,80);
  pros::delay(1500);
  backBarUp(125);
  pros::delay(2000);
  moveRel(0.5,100);
  pros::delay(400);
  turnRel(90,80);
  pros::delay(500);
  moveRel(6,125);
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
