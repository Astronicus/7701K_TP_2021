#include "main.h"
//Motor Setup

#define frntLftMtr_PORT 5
#define frntRghtMtr_PORT 19
#define bckLftMtr_PORT 14
#define bckRghtMtr_PORT 16
#define clampMtr_PORT 3
#define conveyorMtr_PORT 4
#define leftLift_PORT 1
#define rightLift_PORT 2

pros::Controller master (CONTROLLER_MASTER);

pros::Motor frontLeft(frntLftMtr_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor frontRight(frntRghtMtr_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor backLeft(bckLftMtr_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor backRight(bckRghtMtr_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor clampMotor(clampMtr_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor conveyorMotor(conveyorMtr_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor leftLift(leftLift_PORT, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor rightLift(rightLift_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_ROTATIONS);

//Sensor Setup



//3-Wire NOT BEING USED BUT JUST INITIALIZED SO IT'S OK
#define touchPORTA 10
#define touchPORTB 11
#define touchPORTC 12

//V5 Port NOT BEING USED BUT JUST INITIALIZED SO IT'S OK
#define IMU_PORT 19
#define OPTICAL_PORT 17
#define VISION_PORT 18
#define DISTANCE_PORT 16

//Initalization
pros::ADIDigitalIn tapA (touchPORTA);
pros::ADIDigitalIn tapB (touchPORTB);
pros::ADIDigitalIn tapC (touchPORTC);
pros::Imu Inertial(IMU_PORT);
pros::Distance distSensor(DISTANCE_PORT);
pros::Optical Optical(OPTICAL_PORT);
pros::Vision Vision(VISION_PORT);
