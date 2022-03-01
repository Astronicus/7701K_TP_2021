#include "main.h"

/*void turn_imu2(double degrees, double kb, double msTarget) {
  backLeft.tare_position();
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
  double iter=0;
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
      if (fabs(vel) < 15) {
        vel = (fabs(error) / error) * 15;
      }
    }
    vel_error = vel - derror;
    final_vol = (kb * vel);

    printf("%f", Inertial.get_rotation() * imuSign);
    printf("\n");

    move_drive(-final_vol, final_vol);
    //verify robot is at position for a certain period of time
    if (error > -.5 && error < .5) {
      error_sum = 0;
      arrived += 1;
    }
    if (arrived == 1) {
      reset_tracker_wheels();
      brake = fabs(final_vol) / final_vol * -20;
      move_drive(-brake, brake);
      delay(50);
      move_drive(0, 0);
      break;

    }
    if(timeLimit && iter >= msTarget){
      break;
    }
    iter+=10;

    delay(10);
  }
}
*/
