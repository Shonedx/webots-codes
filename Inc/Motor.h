#pragma once
#ifndef MOTOR_H
#define MOTOR_H
#include <Allheads.h>

extern WbDeviceTag motor[8];
extern WbDeviceTag pos[8];
extern double Motor_Velocity[8];
extern double Motor_Angle[8];
extern double Motor_Pos_out[8]; //输出角度缓存区
extern double Motor_Vel_out[8]; //输出速度缓存区
typedef struct
{
    double angle;
    double output_A;
    double velocity;
    double output_V;
    double target_angle;
    double  target_velocity;
}Motor_Property;

void Motor_Init(void);
void Pos_Sensor_Init(void);
void Motor_Sensor_Disable(void);
void Motor_Sensor_Enable(void);
void Motor_Run(void);
void Motor_Pid_Cal(void);


#endif // !MOTOR_H
