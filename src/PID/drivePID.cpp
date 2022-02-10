#include "main.h"

void drivePID(double distance, int maxVoltage, double msTarget){
  frontLeft.tare_position(); //set all motor positions to 0
  frontRight.tare_position();
  backLeft.tare_position();
  backRight.tare_position();

  double sp = distance * 1.5 * 360; //set point

  bool driving = true; //driving true until condition met
  float pConst = 0.2; //set constant values
  float iConst = 0.0;
  float dConst = 0.05;

  double targetPos{}; //initialize all with 0
  double currentPos{};
  double error{};
  double prev_error{};
  double integral{};
  double dError{};

  double kp{};
  double ki{};
  double kd{};

  double giveVoltage{};
  double realVelocity{};

  while(driving){
    targetPos = sp;
    currentPos = (backLeft.get_position() + backRight.get_position())/2;

    prev_error = error;
    error = targetPos - currentPos;
    dError = error - prev_error;

    kp = error * pConst;
    kd = dError * dConst;
    giveVoltage = kp + kd;

    if(abs(giveVoltage > maxVoltage)){
      giveVoltage = maxVoltage * abs(giveVoltage)/giveVoltage; //keep the same sign
    }
    else if (abs(giveVoltage)<20){
      giveVoltage = 25 * abs(giveVoltage)/giveVoltage;
    }




  }

}
