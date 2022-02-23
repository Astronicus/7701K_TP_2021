#include "main.h"

// #define robot_width 13.2 //Changed from 28.3
//#define robot_width 22
// #define wheel_circumfrence 23.9
//#define wheel_circumfrence 31.918581360576  //4in wheel Don't think need this #
#define pi 3.14159

double global_x = 0;
double global_y = 0;
double global_orientation = pi/2;
double orientation_degrees;

double prev_left_pos = 0;
double prev_right_pos = 0;

double right_arc = 0;
double left_arc = 0;
double center_arc = 0;
double delta_angle = 0;
double current_radius = 0;
double center_displacement = 0;
double delta_x = 0;
double delta_y = 0;

int counter = 0;


//tracking function run inside loop
void update_position(){
    right_arc = backRight.get_position()  - prev_right_pos;
    left_arc = backLeft.get_position() - prev_left_pos;
    center_arc = (right_arc + left_arc) / 2.0;

    //convert to degrees (change in angle from 90degree on cordinate plane)
    delta_angle = ((Inertial.get_rotation() * -1.0 * (pi/180.0)) + pi/2) - global_orientation; //  ((right_arc - left_arc) / robot_width)
    global_orientation += delta_angle;
    // if(delta_angle == 0){
    delta_x = cos(global_orientation) * center_arc;
    delta_y = sin(global_orientation) * center_arc;


    prev_right_pos += right_arc;
    prev_left_pos += left_arc;

    global_x += delta_x;
    global_y += delta_y;

    //Print Readout:

    //convert global orientation to degrees
    counter++;
    orientation_degrees = (global_orientation * 180) / pi;

    if(counter%5==0){
    printf( "%f" , global_x);
    printf(", ");
    printf( "%f" , global_y);
    printf(", ");
    printf( "%f" , orientation_degrees);
    printf("\n");
  }
}
