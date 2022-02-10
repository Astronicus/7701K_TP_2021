#include "main.h"

void redFront(){
  /*backBarDown(200);
  chassis::move(-62,175);
  backBarUp(100);
  chassis::move(40,100);
  */

  backBarDown(100);
  moveRel(-3,50);
  pros::delay(1000);
  backBarUp(100);
  pros::delay(1000);
  turnRel(360,50);


}
void skillsRun(){
  backBarDown(200);
  chassis::move(-108,50);
  pros::delay(1000);
  chassis::turn(90,75);
  pros::delay(1000);
  chassis::move(44,50);
}

void redBack(){
  chassis::move(54,100);
  chassis::turn(90,100);
}

void blueFront(){

}

void blueBack(){

}

void autonTest1(){

}
void autonTest2(){

}


void doNothing(){

}
