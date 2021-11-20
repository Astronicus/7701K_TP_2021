#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	//setupSelector();
	selector::init();
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

int auton_num = 0;
void autonomous() {
	chassis::init({5,14},{16,19}, //leftdrive and rightdrive motors
								200, //gearset
								71, //ticks per unit travel CHANGE THIS TO GO FARTHER, UNIT OF TRAVEL SHOULD BE INCHES
								8.0, //ticks per degree CHANGE THIS TO TURN MORE/LESS, UNIT SHOULD BE DEGREES TURN
								8, //settle time
								3, //settle linear
								1, //settle angular
								2, 2, //regular/arc slew
								0, //imu port (none)
								{0,0,0}, //encoder ports
								0, //expander port
								5 //joystick threshhold
	);
	pid::init(false, //debug output
						.3,0,.5, //pid values moving
						.8,0,3, //pid values for turning
						8,0,0, //linear point constants
						50,0,0,//angular point constants
						.05, //arc kp
						0, //dif kp
						3 //min error
	 );

	/* switch(auton_num){
        //Other
        case 1: exampleAuton1(); break;
        case 2: exampleAuton2(); break;
        case 3: exampleAuton3(); break;
        default: break;
    }
		*/

		switch(selector::auton){
	        case 1: redFront(); break;
	        case 2: redBack(); break;
	        case 3: doNothing(); break;
					case -1: blueFront(); break;
					case -2: blueBack(); break;
					case -3: doNothing(); break;
	        default: break;
				}


}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	while (true) {
		//autonTest();
		driveControl();
		intakeControl();
		liftControl();
		clampControl();
		pros::delay(10);
	}
}
