#pragma once
#ifndef  GES_CAL_H
#define  GES_CAL_H
#include <Allheads.h> 
#define Swing_Phase 0.25
typedef struct
{
    double x;
    double z;
    //vmc
    double x_prev;
    double z_prev;
    double Vx;
    double Vz;
    double tao1; //电机力矩
    double tao2;
    double fz;
    double fx;
    //
    double L;
    double L_;//L'
    double sita1; //最终返回的电机角度
    double sita2;//最终返回的电机角度
    double sita3;
    double alpha;
    double offset_A;
    double beta;
} Leg; //和腿部运动有关

typedef struct
{
    Leg leg[4];
  
} Leg_All;
typedef struct
{
    double xf;
    double zf;
}Cycloid;
typedef struct
{
    double Up_Amp; //Amplitude 上升幅度
    double Down_Amp; //下降高度
    double stanceheight; //站立高度
    double steplength;  //迈腿步长
    double freq; //频率
    double swingpercent; //摆动期占比
    double gaitoffset;  //各腿的相位
    int i; //腿序号
    double x_offset; //x初始值
} GaitParams;

void CartesianToTheta_Cycloid(Leg* leg);
//逆解所有腿
void CartesianToTheta_Cycloid_All_Legs(void);
// 设置相关摆动角
void Angle_Setting(int Legid);
// 移动腿函数
void Moveleg(void);
void Stand(void);
void Gait(void);

void SinTrajectory(double t, GaitParams gaitparams);
void Jump_Ctrl();
void IMU_Pos_Cal(double yaw,double pitch,double roll);
void Set_Standheight_Offset(void);


extern double t;
extern Cycloid cycloid;
extern Leg leg;
extern Leg_All leg_all;
extern int state;
#endif // ! GES_CAL_H
