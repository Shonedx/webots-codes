#pragma once
#ifndef PID_H
#define PID_H
#include <Allheads.h>

typedef struct
{
    double Kp;               // 比例增益
    double Ki;               // 积分增益
    double Kd;               // 微分增益

    double max_out;          // 最大输出
    double max_iout;         // 最大积分输出

    double set;              // 设定值
    double fdb;              // 反馈值

    double out;              // 总输出
    double Pout;             // 比例项输出
    double Iout;             // 积分项输出
    double Dout;             // 微分项输出
    double Dbuf;          // 微分项缓存
    double error[3];         // 误差缓存
} PidTypeDef;

//void Pid_Init(void);
//
double constrain(double value, double min, double max);//限制幅度
void Pid_Init(void);
double PID_CAL(PidTypeDef pid, double tar_value, double cur_value);//PID位置环

extern PidTypeDef pos_pid, vel_pid;
#endif // !PID_H
