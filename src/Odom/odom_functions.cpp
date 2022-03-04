#include "main.h"

# define WHEEL_CIRCUMFRENCE 17.01696021 //added gear ratio //10.2101761241668280 // 3.25 in
# define TURN_CONSTANT 1
# define pi 3.14159265359
int imuSign = -1;

extern double global_x;
extern double global_y;
extern double orientation_degrees;
extern int whichPos;

extern double global_orientation0;
extern double global_orientation90;
extern double global_orientation180;
extern double global_orientation270;

extern double global_orientation; //in rad
extern double orientation_degrees;

int count = 0;

void reset_tracker_wheels(){
  //leftEncoder.reset();
  //rightEncoder.reset();
  backLeft.tare_position();
  backRight.tare_position();
}


void move_drive(double vel, double vol){
  frontLeft.move(vel);
  frontRight.move(vol);
  backLeft.move(vel);
  backRight.move(vol);
}


void stop_drive(){
  frontLeft.move(0);
  frontRight.move(0);
  backLeft.move(0);
  backRight.move(0);
  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void turn_imu2(double degrees, double kb, double msTarget) {
  reset_tracker_wheels(); //uses backLeft and backRight
  double target;
  target = ((imuSign * Inertial.get_rotation()) - degrees) * TURN_CONSTANT;
  double init_error = target - (imuSign * Inertial.get_rotation());
  double P_Gain = 1.2;
  double I_Gain = 0.000;
  double D_Gain = 0;
  double prev_error = 0;
  double error = 0;
  double error_sum = 0;
  double derror = 0;
  double vel = 0;
  double vel_error = 0;
  double kp_vel = 0;
  double final_vol = 0;

  int arrived = 0;
  int i_counter = 0;

  double brake = 0;

  bool timeLimit = true;
  int iter=0;
  if(msTarget==0){
    timeLimit=false;
  }

  while (true) {
    error = target - (imuSign * Inertial.get_rotation());
    error_sum += error;

    derror = (error - prev_error) / .01;

    if (fabs(error) > (fabs(init_error) * .75)) {
      P_Gain = 0;
      I_Gain = 0.025;
      D_Gain = 0;

    }
    else{
      P_Gain = 1.2;
      I_Gain = 0;
      D_Gain = 1.5;
      if (fabs(error) < 18) {
        i_counter ++;
        if(i_counter == 1){
          error_sum = 0;
        }
        I_Gain = 0.00;
      }
    }

    //set absolute value of velocity
    vel = (P_Gain * error) + (D_Gain * (derror / 16)) + (I_Gain * error_sum);
    prev_error = error;
    if (fabs(vel) > 100) {
      vel = (fabs(error) / error) * 100;
    }
    if (fabs(error) < (fabs(init_error) * .2)) {
      if (fabs(vel) < 21) {
        vel = (fabs(error) / error) * 21;
      }
    }
    vel_error = vel - derror;
    final_vol = (kb * vel);

    if (iter%100 == 0){
    printf("%f", error);
    printf("\n");
  }


    move_drive(-final_vol, final_vol);
    //verify robot is at position for a certain period of time
    if (error > -.5 && error < .5) {
      error_sum = 0;
      arrived += 1;
    }
    if (arrived == 1) {
      //reset_tracker_wheels();
      brake = fabs(final_vol) / final_vol * -20;
      move_drive(-brake, brake);
      pros::delay(50);
      move_drive(0, 0);
      break;

    }
    if(timeLimit && iter >= msTarget){
      break;
    }
    iter+=10;

    switch(whichPos){
          case 0: update_position0();
          case 90: update_position90();
          case 180: update_position180();
          case 270: update_position270();
          default: update_position90();
      }
    pros::delay(10);
  }
}

void turn_imu(double degrees, double kb) {
  reset_tracker_wheels(); //uses backLeft and backRight
  double target;
  target = ((imuSign * Inertial.get_rotation()) - degrees) * TURN_CONSTANT;
  double init_error = target - (Inertial.get_rotation() * imuSign);
  double P_Gain = 1.2;
  double I_Gain = 0.000;
  double D_Gain = 0;
  double prev_error = 0;
  double error = 0;
  double error_sum = 0;
  double derror = 0;
  double vel = 0;
  double vel_error = 0;
  double kp_vel = 0;
  double final_vol = 0;

  int arrived = 0;
  int i_counter = 0;

  double brake = 0;

  while (true) {
    error = target - (global_orientation);
    error_sum += error;

    derror = (error - prev_error) / .01;

    if (fabs(error) > (fabs(init_error) * .75)) {
      P_Gain = 0;
      I_Gain = 0.025;
      D_Gain = 0;

    }
    else{
      P_Gain = 1.2;
      I_Gain = 0;
      D_Gain = 1.5;
      if (fabs(error) < 18) {
        i_counter ++;
        if(i_counter == 1){
          error_sum = 0;
        }
        I_Gain = 0.00;
      }
    }

    //set absolute value of velocity
    vel = (P_Gain * error) + (D_Gain * (derror / 16)) + (I_Gain * error_sum);
    prev_error = error;
    if (fabs(vel) > 100) {
      vel = (fabs(error) / error) * 100;
    }
    if (fabs(error) < (fabs(init_error) * .2)) {
      if (fabs(vel) < 21) {
        vel = (fabs(error) / error) * 21;
      }
    }
    vel_error = vel - derror;
    final_vol = (kb * vel);

    if (count%10 == 0){
    printf("%f", error);
    printf("\n");
  }


    move_drive(-final_vol, final_vol);
    //verify robot is at position for a certain period of time
    if (error > -.5 && error < .5) {
      error_sum = 0;
      arrived += 1;
    }
    if (arrived == 1) {
      //reset_tracker_wheels();
      brake = fabs(final_vol) / final_vol * -20;
      move_drive(-brake, brake);
      pros::delay(50);
      move_drive(0, 0);
      break;

    }

    switch(whichPos){
          case 0: update_position0();
          case 90: update_position90();
          case 180: update_position180();
          case 270: update_position270();
          default: update_position90();
      }
    pros::delay(10);
    count++;
  }
}

void turn_to_pos(double x, double y, double kb){
  reset_tracker_wheels();
  double target = atan2((y - global_y) , (x - global_x)) * (180/pi);
  double init_error = target - ((imuSign * Inertial.get_rotation()) - whichPos);
  double p_constant = 1.2;
  double i_constant = 0.000;
  double d_constant = 0;
  double last_dif = 0;
  double dif = 0;
  double total_dif = 0;
  double der = 0;
  double vel = 0;
  double vel_error = 0;
  double kp_vel = 0;
  double final_vol = 0;

  int arrived = 0;
  int i_counter = 0;

  double brake = 0;
  while (true) {
    dif = target - ((-1 * Inertial.get_rotation()) + 90);
    total_dif += dif;

    der = (dif - last_dif) / .01;

    if (fabs(dif) > (fabs(init_error) * .75)) {
      p_constant = 0;
      i_constant = 0.025;
      d_constant = 0;

    }
    else{
      p_constant = 1.2;
      i_constant = 0;
      d_constant = 1.5;
      if (fabs(dif) < 18) {
        i_counter ++;
        if(i_counter == 1){
          total_dif = 0;
        }
        i_constant = 0.00;
      }
    }

    //set absolute value of velocity
    vel = (p_constant * dif) + (d_constant * (der / 16)) + (i_constant * total_dif);
    last_dif = dif;
    if (fabs(vel) > 80) {
      vel = (fabs(dif) / dif) * 80;
    }
    if (fabs(dif) < (fabs(init_error) * .2)) {
      if (fabs(vel) < 21) {
        vel = (fabs(dif) / dif) * 21;
      }
    }
    vel_error = vel - der;
    final_vol = (kb * vel);


    count++;
    if(count%10==0){
      printf("%f", Inertial.get_rotation() * -1);
      printf("\n");
    }


    move_drive(-final_vol, final_vol);
    //verify robot is at position for a certain period of time
    if (dif > -2 && dif < 2) {
      total_dif = 0;
      arrived += 1;
    }
    if (arrived == 4) {
      reset_tracker_wheels();
      // brake = fabs(final_vol) / final_vol * -20;
      // move_drive(-brake, brake);
      // pros::delay(50);
      move_drive(0, 0);
      break;

    }
    switch(whichPos){
	        case 0: update_position0();
	        case 90: update_position90();
	        case 180: update_position180();
					case 270: update_position270();
	        default: update_position90();
	    }

    pros::delay(10);
  }
}

void curvy_odom(double max_vel, double xf, double yf, double zone, double zone_constant) {

  double error;
  double init_error = sqrt(pow((global_x - xf), 2) + pow((global_y - yf), 2));
  double total_error;
  double desired_angle = atan2((yf - global_y) , (xf - global_x));
  double init_angle_error = desired_angle - global_orientation;
  double angle_error;
  double correction;
  double vel_target;
  double vel_error;
  double final_vol;
  double arrived = 0;

  double kB = 1;
  double kp = .2;
  double kd = 0;
  double ki = .002;

  double kpa = .02;

  double kc = .2;

  double vel_kp;
  double i_counter;

  double flip = 1;

  double init_length = fabs(backLeft.get_position());
  double length = 0;

  while (true) {
    length = fabs(fabs(backLeft.get_position()) - init_length);
    error = sqrt(pow((global_x - xf), 2) + pow((global_y - yf), 2));
    total_error += error;
    desired_angle = atan2((yf - global_y) , (xf - global_x));


    if (fabs(error) > (fabs(init_error) * .75)) {
      kp = 0;
      ki = 0.00002;
      kd = 0;

    }
    else{
      kp = .3;
      ki = 0;
      kd = .2;
      if (fabs(error) < 184.4) {
        ki = 0;
        i_counter ++;
        if(i_counter == 1){
          total_error = 0;
        }
      }
    }
    angle_error = desired_angle - global_orientation;
    if(fabs(init_angle_error) > pi){
      if(fabs(desired_angle) / desired_angle == 1){
        desired_angle -= 2*pi;
        angle_error = desired_angle - global_orientation;
      }
      else{
        desired_angle += 2* pi;
        angle_error = desired_angle - global_orientation;
      }
    }
    vel_target = flip * ((error * kp) + (total_error * ki));
    final_vol = kB * vel_target;
     if (fabs(final_vol) > max_vel) {
      final_vol = fabs(final_vol) / final_vol * max_vel;
    }


    if(fabs(length) < zone){
      correction = zone_constant;
      if(flip == 1){
        if(fabs(angle_error) / angle_error == 1){
          move_drive(final_vol * correction, final_vol);
        }
        if(fabs(angle_error) / angle_error == -1){
          move_drive(final_vol, final_vol * correction);
        }
      }
      else{
        if(fabs(angle_error) / angle_error == -1){
          move_drive(final_vol * correction, final_vol);
        }
        if(fabs(angle_error) / angle_error == 1){
          move_drive(final_vol, final_vol * correction);
        }
      }
    }
    else{

      correction = .8 - (kpa * fabs(angle_error * (180 / pi)));
      if (correction < .1){
        correction = .1;
      }

        if(flip == 1){
          if(fabs(angle_error) / angle_error == 1){
            move_drive(final_vol * correction, final_vol);
          }
          if(fabs(angle_error) / angle_error == -1){
            move_drive(final_vol, final_vol * correction);
          }
          if(fabs(angle_error) / angle_error == 0){
            move_drive(final_vol, final_vol);
          }
        }
        else{
          if(fabs(angle_error) / angle_error == -1){
            move_drive(final_vol * correction, final_vol);
          }
          if(fabs(angle_error) / angle_error == 1){
            move_drive(final_vol, final_vol * correction);
          }
          if(fabs(angle_error) / angle_error == 0){
            move_drive(final_vol, final_vol);
          }
        }
    }

    if (error < 50) {
      arrived++;
    }
    if (arrived == 1) {
      move_drive(0, 0);
      break;
    }

    switch(whichPos){
          case 0: update_position0();
          case 90: update_position90();
          case 180: update_position180();
          case 270: update_position270();
          default: update_position90();
      }
    count++;
    printf("%f", desired_angle);
    printf("\n");
  }
}
