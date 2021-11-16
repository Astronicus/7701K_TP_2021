#include "main.h"

void drivePID(double distance, int speed, double msTarget){
  frontLeft.tare_position(); //set all motor positions to 0
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  bool driving = true;
  float pConst = 0.2;
  float iConst = 0.0;
  float dConst = 0.05;

  float targetPos{};
  float currentPos{};
  float error{};
  float prev_error{};
  float integral{};

  float kp{};
  float ki{};
  float kd{};

  while(driving){
    targetPos = distance;
    currentPos = (backLeft.get_position() + backRight.get_position())/2;
    prev_error = error;
    error = targetPos - currentPos;


    kp = error * pConst;
    kd =


  }

}
