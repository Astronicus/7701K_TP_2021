#include "main.h"

/*void hookRotate(float rotations, float velocity){
  hookMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  hookMotor.move_relative(rotations, velocity);
  pros::delay(100);
}
*/

void backBarDown(float velocity){
  backFourBarMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backFourBarMotor.move_relative(-50, velocity);
  pros::delay(0);
}
void backBarUp(float velocity){
  backFourBarMotor.move_relative(50, velocity);
  //pros::delay(750);
}
void moveRel(float distance, float velocity){
  distance*=1.5;
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  frontLeft.move_absolute(distance, velocity ); // * driveMultiplier
  frontRight.move_absolute(distance, velocity);
  backLeft.move_absolute(distance, velocity);
  backRight.move_absolute(distance, velocity);

  while (!((frontLeft.get_position() < (distance+0.15)) && (frontLeft.get_position() > distance-0.15))) {
  pros::delay(2);
}
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();
}

void turnRel(float distance, float velocity){
  distance*=3;
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  frontLeft.move_absolute(-distance, velocity ); // * driveMultiplier
  frontRight.move_absolute(distance, velocity);
  backLeft.move_absolute(-distance, velocity);
  backRight.move_absolute(distance, velocity);

  int counter = 0;
  while (!((frontLeft.get_position() < (distance+0.30)) && (frontLeft.get_position() > distance-0.30))) {
  pros::delay(2);
  counter++;

  if(counter%50 == 0){
    printf("%f\n",frontLeft.get_position());
  }

}
  frontLeft.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();
}

void armMove(float distance, float velocity){
  leftLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  rightLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftLift.move_relative(distance, velocity);
  rightLift.move_relative(distance, velocity);
  pros::delay(50);
}
