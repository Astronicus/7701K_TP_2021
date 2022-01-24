#include "main.h"

void redFront(){
  //odom::move({48,0},100);
  //hookRotate(0.7,100);
  //odom::move({10,0},70);
  backBarDown(100);
  chassis::move(-54,100);
  backBarUp(100);
  chassis::move(30,100);


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

void autonTest1(){
  odom::move({54,0},100);
  chassis::turn(180,70);
  hookRotate(0.6,100);
}
void autonTest2(){

}


void doNothing(){

}
