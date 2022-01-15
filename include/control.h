#ifndef CONTROL_H
#define CONTROL_H

//inmatch controls
void driveControl();
void backFourBarControl();
void liftControl();
void hookControl();
void backBarUp();
void backBarDown();

//auton methods
void hookRotate(float degrees, float vel);
void backBarUp(float velocity);
void backBarDown(float velocity);
void moveRel(float distance, float velocity);

#endif
