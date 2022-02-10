#include "main.h"

void leftAuton(){
  backBarDown(200);
	moveRel(-2.05,125);
	pros::delay(500);
	backBarUp(100);
	pros::delay(1000);
	moveRel(1.8,150);
}

void rightAuton(){
  backBarDown(200);
  moveRel(-2.05,125);
  pros::delay(500);
  backBarUp(100);
  pros::delay(1000);
  moveRel(1.8,150);
}

void leftWPAuton(){

}

void rightWPAuton(){

}

void skillsRun(){
  backBarDown(200);
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
