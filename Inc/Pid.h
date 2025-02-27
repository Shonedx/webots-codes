#pragma once
#ifndef PID_H
#define PID_H
#include <Allheads.h>

typedef struct
{
    double Kp;               // ��������
    double Ki;               // ��������
    double Kd;               // ΢������

    double max_out;          // ������
    double max_iout;         // ���������

    double set;              // �趨ֵ
    double fdb;              // ����ֵ

    double out;              // �����
    double Pout;             // ���������
    double Iout;             // ���������
    double Dout;             // ΢�������
    double Dbuf;          // ΢�����
    double error[3];         // ����
} PidTypeDef;

//void Pid_Init(void);
//
double constrain(double value, double min, double max);//���Ʒ���
void Pid_Init(void);
double PID_CAL(PidTypeDef pid, double tar_value, double cur_value);//PIDλ�û�

extern PidTypeDef pos_pid, vel_pid;
#endif // !PID_H
