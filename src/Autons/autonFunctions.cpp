#include "main.h"

/*void hookRotate(float rotations, float velocity){
  hookMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  hookMotor.move_relative(rotations, velocity);
  pros::delay(100);
}
*/

void backBarDown(float velocity){
  backFourBarMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  backFourBarMotor.move_relative(-2.5, velocity);
  pros::delay(0);
}
void backBarUp(float velocity){
  backFourBarMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  backFourBarMotor.move_relative(2.5, velocity);
  //pros::delay(750);
}

void barWhileMoveRel(float distance1, float distance2, float velocity1, float velocity2){
  distance1*=1.5*360;
  distance2*=1.5*360;
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  frontLeft.move_absolute(distance1, velocity1 ); // * driveMultiplier
  frontRight.move_absolute(distance1, velocity1);
  backLeft.move_absolute(distance1, velocity1);
  backRight.move_absolute(distance1, velocity1);

  while (!((frontLeft.get_position() < (distance1+10)) && (frontLeft.get_position() > distance1-10))) {
    pros::delay(2);
  }

  backBarUp(200);

  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  frontLeft.move_absolute(distance2, velocity2 ); // * driveMultiplier
  frontRight.move_absolute(distance2, velocity2);
  backLeft.move_absolute(distance2, velocity2);
  backRight.move_absolute(distance2, velocity2);

  while (!((frontLeft.get_position() < (distance2+10)) && (frontLeft.get_position() > distance2-10))) {
    pros::delay(2);
  }
  pros::delay(350);
}

void moveRel(float distance, float velocity){
  distance*=1.5*360;
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  frontLeft.move_absolute(distance, velocity ); // * driveMultiplier
  frontRight.move_absolute(distance, velocity);
  backLeft.move_absolute(distance, velocity);
  backRight.move_absolute(distance, velocity);

  int counter = 0;
  while (!((frontLeft.get_position() < (distance+10)) && (frontLeft.get_position() > distance-10))) {
  pros::delay(2);
  counter++;
  if(counter>3000){
    break;
  }
}
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();
  pros::delay(350);
}
void moveTime(float distance, float velocity, float time){
  distance*=1.5*360;
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  frontLeft.move_absolute(distance, velocity ); // * driveMultiplier
  frontRight.move_absolute(distance, velocity);
  backLeft.move_absolute(distance, velocity);
  backRight.move_absolute(distance, velocity);

  pros::delay(time);
}

void turnRel(float distance, float velocity){
  distance*=(-2.93);
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  frontLeft.move_absolute(-distance, velocity ); // * driveMultiplier
  frontRight.move_absolute(distance, velocity);
  backLeft.move_absolute(-distance, velocity);
  backRight.move_absolute(distance, velocity);

  int counter = 0;
  while (distance - abs(frontLeft.get_position()) > 10) pros::delay(10);
  //counter++;

  /*if(counter%50 == 0){
    printf("%f\n",frontLeft.get_position());
  }
  */
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();
  pros::delay(500);
}

void armMove(float distance, float velocity){
  distance*=2.92;
  leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftLift.move_relative(distance, velocity);
  rightLift.move_relative(distance, velocity);
  pros::delay(50);
}
