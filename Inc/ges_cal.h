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
    double tao1; //�������
    double tao2;
    double fz;
    double fx;
    //
    double L;
    double L_;//L'
    double sita1; //���շ��صĵ���Ƕ�
    double sita2;//���շ��صĵ���Ƕ�
    double sita3;
    double alpha;
    double offset_A;
    double beta;
} Leg; //���Ȳ��˶��й�

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
    double Up_Amp; //Amplitude ��������
    double Down_Amp; //�½��߶�
    double stanceheight; //վ���߶�
    double steplength;  //���Ȳ���
    double freq; //Ƶ��
    double swingpercent; //�ڶ���ռ��
    double gaitoffset;  //���ȵ���λ
    int i; //�����
    double x_offset; //x��ʼֵ
} GaitParams;

void CartesianToTheta_Cycloid(Leg* leg);
//���������
void CartesianToTheta_Cycloid_All_Legs(void);
// ������ذڶ���
void Angle_Setting(int Legid);
// �ƶ��Ⱥ���
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
