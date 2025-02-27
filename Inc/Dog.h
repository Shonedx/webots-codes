#pragma once
#ifndef DOG_H
#define DOG_H
#include <Allheads.h>
#define TIME_STEP 1
#define Sampling_period 1
#define Max_Speed 94.2//94.2
#define PI 3.14159265358979323846
#define StandHeight 17.3 //17.3
#define X_OFFSET 0
#define L1 10  //cm
#define L2 20 //cm
#define dl 1.5 //cm
//======================
#define LENGTH	34	//机体长度 cm
#define Width	26	//机体宽度 cm
#define thickness 4 //电机厚度 cm
#define WIDTH 34 //计算imu的总宽度 cm
//====================
#define Freq 1.87//1.5-4
#define dt TIME_STEP/1000 
void delay_ms(int milliseconds);
extern double roll;
extern double yaw;
extern double pitch;


#endif // !DOG_H
