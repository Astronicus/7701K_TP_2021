#include "main.h"

void leftAuton(){
  setWhichPos(90);
  turn_imu2(180, 1, 3000);

  /*backBarDown(200);
  pros::delay(100);
	barWhileMoveRel(-2.05,-0.45,200,200);
  pros::delay(250);
	backBarUp(150);
	pros::delay(150);
	moveRel(2.1,200);
  turnRel(180,100);
  */

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
  pros::delay(300);
  barWhileMoveRel(-2.8,-1.0,150,150);
  pros::delay(450);
  moveRel(2.5,100);


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
  moveRel(1.1,100);
  pros::delay(250);
  turnRel(180,150);
  pros::delay(450);
  backBarDown(200);
  pros::delay(750);
  moveRel(2.0,100);

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
  moveRel(-2.73,100);
  pros::delay(500);
  moveRel(0.2,100);
  pros::delay(500);
  turnRel(-69,80);
  pros::delay(500);
  backBarDown(200);
  pros::delay(1000);
  moveTime(-1.62,80,3000);
  pros::delay(1500);
  backBarUp(125);
  pros::delay(2000);
  moveRel(0.75,100);
  pros::delay(400);
  turnRel(83,80);
  pros::delay(500);
  moveRel(6,125);
}

void skillsRun2(){
  openPistons();
  armMove(1,100);
  pros::delay(2750);
  moveRel(0.6,75);
  pros::delay(500);
  closePistons();
  armMove(-0.90,100);
  pros::delay(2750);
  moveTime(-1.0,75,3000);
  //back to orig position

  moveRel(0.16,50);
  pros::delay(500);
  turnRel(90,100);
  pros::delay(400);
  backBarDown(200);
  pros::delay(300);
  moveRel(-3.5,150);
  pros::delay(300);
  backBarUp(100);
  turnRel(-90,100);
  pros::delay(500);
  moveRel(1,100);
  armMove(0.9,100);
  pros::delay(2500);
  openPistons();
  moveRel(-0.5,100);
  armMove(-0.9,100);
  pros::delay(1500);
  turnRel(180,100);
  pros::delay(1500);
  moveRel(0.6,50);
//against the wall facing perpendicular
  turnRel(90,100);
  moveRel(-3,100);
  pros::delay(500);
  backBarDown(200);
  pros::delay(1000);
  moveRel(0.5,100);
  backBarUp(200);
  pros::delay(1000);

  //two goals, now rest of regular skills run

  turnRel(50,100);
  moveRel(3.1,100);
  moveRel(-0.2,100);
  turnRel(-58,80);
  moveRel(-2.83,100);
  pros::delay(500);
  moveRel(0.2,100);
  pros::delay(500);
  turnRel(-65,80);
  pros::delay(500);
  backBarDown(200);
  pros::delay(1000);
  moveTime(-1.80,50,3000);
  pros::delay(1000);
  backBarUp(125);
  pros::delay(2000);
  moveRel(0.5,100);
  pros::delay(400);
  turnRel(78,80);
  pros::delay(500);
  moveRel(6,125);



}

void skillsRun3(){

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
