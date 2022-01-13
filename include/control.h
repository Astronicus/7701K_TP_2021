#ifndef CONTROL_H
#define CONTROL_H

void driveControl();
void backFourBarControl();
void liftControl();
void hookControl();
void backBarUp();
void backBarDown();

void hookRotate(float degrees, float vel);
void backBarUp(float velocity);
void backBarDown(float velocity);
void moveRel(float distance, float velocity);

#endif
