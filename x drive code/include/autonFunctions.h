#ifndef AUTONFUNTIONS_H
#define AUTONFUNTIONS_H

void inertialCalibration();
void reset();
int drivePID(int target);
int strafeLeftPID(int target);
void moveForward(void);
#endif
