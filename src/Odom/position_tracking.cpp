#include "main.h"

// #define robot_width 13.2 //Changed from 28.3
//#define robot_width 22
// #define wheel_circumfrence 23.9
//#define wheel_circumfrence 31.918581360576  //4in wheel Don't think need this #
#define pi 3.14159

double global_x = 0;
double global_y = 0;

double global_orientation0 = 0;
double global_orientation90 = pi/2;
double global_orientation180 = pi;
double global_orientation270 = 3*pi/2;
double global_orientation = 0;

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
int whichPos = -1;


//tracking function run inside loop
void update_position90(){
    right_arc = backRight.get_position()  - prev_right_pos;
    left_arc = backLeft.get_position() - prev_left_pos;
    center_arc = (right_arc + left_arc) / 2.0;

    //convert to degrees (change in angle from 90degree on cordinate plane)
    delta_angle = ((Inertial.get_rotation() * -1.0 * (pi/180.0)) + pi/2) - global_orientation90; //  ((right_arc - left_arc) / robot_width)
    global_orientation90 += delta_angle;
    global_orientation = global_orientation90;
    // if(delta_angle == 0){
    delta_x = cos(global_orientation90) * center_arc;
    delta_y = sin(global_orientation90) * center_arc;


    prev_right_pos += right_arc;
    prev_left_pos += left_arc;

    global_x += delta_x;
    global_y += delta_y;

    //Print Readout:

    //convert global orientation to degrees
    counter++;
    orientation_degrees = (global_orientation90 * 180) / pi;

    if(counter%5==0){
    printf( "%f" , global_x);
    printf(", ");
    printf( "%f" , global_y);
    printf(", ");
    printf( "%f" , orientation_degrees);
    printf("\n");
  }
}

void update_position180(){
    right_arc = backRight.get_position()  - prev_right_pos;
    left_arc = backLeft.get_position() - prev_left_pos;
    center_arc = (right_arc + left_arc) / 2.0;

    //convert to degrees (change in angle from 90degree on cordinate plane)
    delta_angle = ((Inertial.get_rotation() * -1.0 * (pi/180.0)) + pi) - global_orientation180; //  ((right_arc - left_arc) / robot_width)
    global_orientation180 += delta_angle;
    global_orientation = global_orientation180;
    // if(delta_angle == 0){
    delta_x = cos(global_orientation180) * center_arc;
    delta_y = sin(global_orientation180) * center_arc;


    prev_right_pos += right_arc;
    prev_left_pos += left_arc;

    global_x += delta_x;
    global_y += delta_y;

    //Print Readout:

    //convert global orientation to degrees
    counter++;
    orientation_degrees = (global_orientation180 * 180) / pi;

    if(counter%5==0){
    printf( "%f" , global_x);
    printf(", ");
    printf( "%f" , global_y);
    printf(", ");
    printf( "%f" , orientation_degrees);
    printf("\n");
  }
}

void update_position270(){
    right_arc = backRight.get_position()  - prev_right_pos;
    left_arc = backLeft.get_position() - prev_left_pos;
    center_arc = (right_arc + left_arc) / 2.0;

    //convert to degrees (change in angle from 90degree on cordinate plane)
    delta_angle = ((Inertial.get_rotation() * -1.0 * (pi/180.0)) + 3*pi/2) - global_orientation270; //  ((right_arc - left_arc) / robot_width)
    global_orientation270 += delta_angle;
    global_orientation = global_orientation270;
    // if(delta_angle == 0){
    delta_x = cos(global_orientation270) * center_arc;
    delta_y = sin(global_orientation270) * center_arc;


    prev_right_pos += right_arc;
    prev_left_pos += left_arc;

    global_x += delta_x;
    global_y += delta_y;

    //Print Readout:

    //convert global orientation to degrees
    counter++;
    orientation_degrees = (global_orientation270 * 180) / pi;

    if(counter%5==0){
    printf( "%f" , global_x);
    printf(", ");
    printf( "%f" , global_y);
    printf(", ");
    printf( "%f" , orientation_degrees);
    printf("\n");
  }
}

void update_position0(){
    right_arc = backRight.get_position()  - prev_right_pos;
    left_arc = backLeft.get_position() - prev_left_pos;
    center_arc = (right_arc + left_arc) / 2.0;

    //convert to degrees (change in angle from 90degree on cordinate plane)
    delta_angle = (Inertial.get_rotation() * -1.0 * (pi/180.0)) - global_orientation0; //  ((right_arc - left_arc) / robot_width)
    global_orientation0 += delta_angle;
    global_orientation = global_orientation0;
    // if(delta_angle == 0){
    delta_x = cos(global_orientation0) * center_arc;
    delta_y = sin(global_orientation0) * center_arc;


    prev_right_pos += right_arc;
    prev_left_pos += left_arc;

    global_x += delta_x;
    global_y += delta_y;

    //Print Readout:

    //convert global orientation to degrees
    counter++;
    orientation_degrees = (global_orientation0 * 180) / pi;

    if(counter%5==0){
    printf( "%f" , global_x);
    printf(", ");
    printf( "%f" , global_y);
    printf(", ");
    printf( "%f" , orientation_degrees);
    printf("\n");
  }
}

void setWhichPos(int setPos){
  switch(setPos){
        case 0: whichPos = 0;
        case 90: whichPos = 90;
        case 180: whichPos = 180;
        case 270: whichPos = 270;
        default: whichPos = -1;
        }

  switch(setPos){
        case 0: global_orientation = global_orientation0;
        case 90: global_orientation = global_orientation90;
        case 180: global_orientation = global_orientation180;
        case 270: global_orientation = global_orientation270;
}
}
