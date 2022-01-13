#include "main.h"

void hookRotate(float rotations, float velocity){
  hookMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  hookMotor.move_relative(rotations, velocity);
  pros::delay(100);
}

void backBarDown(float velocity){
  backFourBarMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backFourBarMotor.move_relative(-50, velocity);
  pros::delay(0);
}
void backBarUp(float velocity){
  backFourBarMotor.move_relative(50, velocity);
  pros::delay(1500);
}
void moveRel(float distance, float velocity){
  distance = distance * 360;
  frontLeft.move_relative(distance, velocity ); // * driveMultiplier
  frontRight.move_relative(distance, velocity);
  backLeft.move_relative(distance, velocity);
  backRight.move_relative(distance, velocity);
  pros::delay(1900);

}
