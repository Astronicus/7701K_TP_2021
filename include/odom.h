#ifndef ODOM_H
#define ODOM_H

void reset_tracker_wheels();
void move_drive(double vel, double vol);
void turn_imu2(double degrees, double kb, double msTarget);
void turn_imu(double degrees, double kb);
void setWhichPos(int setPos);

#endif
