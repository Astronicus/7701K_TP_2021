#include "main.h"
//Motor Setup

#define frntLftMtr_PORT 17
#define frntRghtMtr_PORT 16
#define bckLftMtr_PORT 19
#define bckRghtMtr_PORT 15
#define hook_PORT 4
#define backFourBar_PORT 20
#define leftLift_PORT 14
#define rightLift_PORT 18

#define piston_PORT 'A'

pros::Controller master (CONTROLLER_MASTER);

pros::Motor frontLeft(frntLftMtr_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor frontRight(frntRghtMtr_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor backLeft(bckLftMtr_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor backRight(bckRghtMtr_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
//pros::Motor hookMotor(hook_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor backFourBarMotor(backFourBar_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor leftLift(leftLift_PORT, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor rightLift(rightLift_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::ADIDigitalOut piston (piston_PORT);

//Sensor Setup



//3-Wire NOT BEING USED BUT JUST INITIALIZED SO IT'S OK
#define touchPORTA 8
#define touchPORTB 9
#define touchPORTC 10

//Initalization
pros::ADIDigitalIn tapA (touchPORTA);
pros::ADIDigitalIn tapB (touchPORTB);
pros::ADIDigitalIn tapC (touchPORTC);
