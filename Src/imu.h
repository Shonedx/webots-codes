#ifndef IMU_H
#define IMU_H
#include <Allheads.h>
void Imu_Enable(void);
void Imu_Disable(void);
const double* Imu_GetAngle(WbDeviceTag tag);
void Imu_Init(void);

#endif // !IMU_H
