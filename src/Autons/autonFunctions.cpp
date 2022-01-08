#include "main.h"

void hookRotate(float rotations, float velocity){
  hookMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  hookMotor.move_relative(rotations, velocity);
  pros::delay(100);
}
