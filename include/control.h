#ifndef CONTROL_H
#define CONTROL_H

//inmatch controls
void driveControl();
void backFourBarControl();
void liftControl();
void hookControl();
void backBarUp();
void backBarDown();
void driveControlARMS();
void driveControlH();

//auton methods
void hookRotate(float degrees, float vel);
void backBarUp(float velocity);
void backBarDown(float velocity);
void moveRel(float distance, float velocity);
void armMove(float distance, float velocity);
void turnRel(float distance, float velocity);

#endif
