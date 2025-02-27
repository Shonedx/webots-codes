#include <ges_cal.h>
 Leg_All leg_all;
 double t = 0;
  double standheight[4] = {StandHeight,StandHeight,StandHeight ,StandHeight};
  double  x_offset[4] = { 0,0,0,0 };
  extern int Jump_OK;

 void printf_state(State currentstate)
 {
	 switch (currentstate)
	 {
	 case Idle:  // 原地踏步
		 printf("currentstate:Idle\n");
		 break;
	 case Forward:
		 printf("currentstate:Forward\n");
		 break;
	 case Back:
		 printf("currentstate:Back\n");
		 break;
	 case Turn_Left:
		 printf("currentstate:Turn_Left\n");
		 break;
	 case Turn_Right:
		 printf("currentstate:Turn_Right\n");
		 break;
	 case Jump:
		 printf("currentstate:Jump\n");
		 break;
	 case Stop:
		 printf("currentstate:Stop\n");
		 break;
	 }
 }
 

 GaitParams Gait_Params[][4] = {
	  //	Up_Amp Down_Amp stanceheight steplength freq swingpercent gaitoffset i x_offset
	  //	上升幅度 下降高度 站立高度 迈腿步长 频率 摆动期占比 各腿的相位 腿序号 x初始值
	{//原地踏步（待机）状态 0
		{ 4, 0.2, StandHeight, 0, Freq, 0.25, 0, 0,X_OFFSET},
		{ 4, 0.2, StandHeight, 0, Freq, 0.25, 0.5, 1,X_OFFSET},
		{ 4, 0.2, StandHeight, 0, Freq, 0.25, 0.5, 2,X_OFFSET},
		{ 4, 0.2, StandHeight, 0, Freq, 0.25, 0, 3,X_OFFSET},
	},
	  {//前进状态 1
		{ 5, 0.2, StandHeight, 16, Freq, 0.25, 0, 0,X_OFFSET},
		{ 5, 0.2, StandHeight, 16, Freq, 0.25, 0.5, 1,X_OFFSET},
		{ 5, 0.2, StandHeight, 16, Freq, 0.25, 0.5, 2,X_OFFSET},
		{ 5, 0.2, StandHeight, 16, Freq, 0.25, 0, 3,X_OFFSET},
	},
	  {//后退状态 2
		{ 5, 0.2, StandHeight, -16, Freq, 0.25, 0, 0,X_OFFSET},
		{ 5, 0.2, StandHeight,-16, Freq, 0.25, 0.5, 1,X_OFFSET},
		{ 5, 0.2, StandHeight, -16, Freq, 0.25, 0.5, 2,X_OFFSET},
		{ 5, 0.2, StandHeight, -16, Freq, 0.25, 0, 3,X_OFFSET},
	},
	{//左转弯状态 3
		{ 4, 0.2, StandHeight, -8, 3, 0.25, 0, 0,X_OFFSET},
		{ 4, 0.2, StandHeight, 8, 3, 0.25, 0.5, 1,X_OFFSET},
		{ 4, 0.2, StandHeight, -8, 3, 0.25, 0.5, 2,X_OFFSET},
		{ 4, 0.2, StandHeight, 8, 3, 0.25, 0, 3,X_OFFSET},
	},
	{//右转弯状态 4
		{ 4, 0.2, StandHeight, 8, 3, 0.25, 0, 0,X_OFFSET},
		{ 4, 0.2, StandHeight, -8, 3, 0.25, 0.5, 1,X_OFFSET},
		{ 4, 0.2, StandHeight, 8, 3, 0.25, 0.5, 2,X_OFFSET},
		{ 4, 0.2, StandHeight, -8, 3, 0.25, 0, 3,X_OFFSET},
	},

	{//停止 5
		{ 0, 0, StandHeight, 0, 0, 0, 0, 0,X_OFFSET},
		{ 0, 0, StandHeight, 0, 0, 0, 0, 1,X_OFFSET},
		{ 0, 0, StandHeight, 0, 0, 0, 0, 2,X_OFFSET},
		{ 0, 0, StandHeight, 0, 0, 0, 0, 3,X_OFFSET},
	},
	//Climbing
	{//原地踏步（待机）状态 0+6
		{ 3, 0.1, StandHeight, 0, 3, 0.25, 0, 0,X_OFFSET},
		{ 3, 0.1, StandHeight, 0, 3, 0.25, 0.5, 1,X_OFFSET},
		{ 3, 0.1, StandHeight, 0, 3, 0.25, 0.5, 2,X_OFFSET},
		{ 3, 0.1, StandHeight, 0, 3, 0.25, 0, 3,X_OFFSET},
	},
	{//前进状态 1+6
		{ 3, 0.1, StandHeight, 3, 3, 0.25, 0, 0,X_OFFSET},
		{ 3, 0.1, StandHeight, 3, 3, 0.25, 0.5, 1,X_OFFSET},
		{ 3, 0.1, StandHeight, 3, 3, 0.25, 0.5, 2,X_OFFSET},
		{ 3, 0.1, StandHeight, 3, 3, 0.25, 0, 3,X_OFFSET},
	},
	  {//后退状态 2+6
		{ 3, 0.1, StandHeight, -4, 3, 0.25, 0, 0,X_OFFSET},
		{ 3, 0.1, StandHeight,-4, 3, 0.25, 0.5, 1,X_OFFSET},
		{ 3, 0.1, StandHeight, -4, 3, 0.25, 0.5, 2,X_OFFSET},
		{ 3, 0.1, StandHeight, -4, 3, 0.25, 0, 3,X_OFFSET},
	},
	{//左转弯状态 3+6
		{ 3, 0.1, StandHeight, -4, 3, 0.25, 0, 0,X_OFFSET},
		{ 3, 0.1, StandHeight, 4, 3, 0.25, 0.5, 1,X_OFFSET},
		{ 3, 0.1, StandHeight, -4, 3, 0.25, 0.5, 2,X_OFFSET},
		{ 3, 0.1, StandHeight, 4, 3, 0.25, 0, 3,X_OFFSET},
	},
	{//右转弯状态 4+6
		{ 3, 0.1, StandHeight, 4, 3, 0.25, 0, 0,X_OFFSET},
		{ 3, 0.1, StandHeight, -4, 3, 0.25, 0.5, 1,X_OFFSET},
		{ 3, 0.1, StandHeight, 4, 3, 0.25, 0.5, 2,X_OFFSET},
		{ 3, 0.1, StandHeight, -4, 3, 0.25, 0, 3,X_OFFSET},
	},
  };
 void Set_Standheight_Offset(void)
 {
	 for (int i = 0; i < 10; i++)
	 {
		 for (int j = 0; j < 4; j++)
		 {
			 Gait_Params[i][j].stanceheight = standheight[j];
			 Gait_Params[i][j].x_offset = x_offset[j];
		 }
	 }
	 printf("standheight:%f,%f,%f,%f\n", standheight[0], standheight[1], standheight[2], standheight[3]);
 }
  int state = 0;
// 逆解函数
void Gait(void)
{
	t = wb_robot_get_time();

	switch (currentstate)
	{
	case Idle:  // 原地踏步
		for (int i = 0; i < 4; i++)
		{
			SinTrajectory(t, Gait_Params[0][i]);
		}

		break;
	case Forward:
		for (int i = 0; i < 4; i++)
		{
			SinTrajectory(t, Gait_Params[1 ][i]);
		}

		break;
	case Back:
		for (int i = 0; i < 4; i++)
		{
			SinTrajectory(t, Gait_Params[2 ][i]);
		}

		break;
	case Turn_Left:
		for (int i = 0; i < 4; i++)
		{
			SinTrajectory(t, Gait_Params[3 ][i]);
		}

		break;
	case Turn_Right:
		for (int i = 0; i < 4; i++)
		{
			SinTrajectory(t, Gait_Params[4 ][i]);
		}

		break;
	case Jump:
	
		Execute_Jump();
		break;
	case Stop:
		for (int i = 0; i < 4; i++)
		{
			SinTrajectory(t, Gait_Params[5][i]);
		}
		Jump_OK = 1;

		break;
	}
	//printf_state(currentstate);

	// 转换到逆运动学的角度
	CartesianToTheta_Cycloid_All_Legs();
	// 控制腿部运动
	Moveleg();
}
void SinTrajectory(double t, GaitParams gaitparams)
{
	double x, z, gp;
	static double p = 0;
	static double prev_t = 0;
	p += gaitparams.freq * (t - prev_t);
	prev_t = t;
	gp = fmod(p + gaitparams.gaitoffset, 1.0);
	/*gp *= legs_freq.freq[gaitparams.i];*/
	if (gp <= gaitparams.swingpercent) {
		x = (gp / gaitparams.swingpercent) * gaitparams.steplength - gaitparams.steplength / 2.0+ gaitparams.x_offset;
		z = -gaitparams.Up_Amp * sin(PI * gp / gaitparams.swingpercent) + gaitparams.stanceheight;
	}
	else {
		float percentBack = (gp - gaitparams.swingpercent) / (1.0 - gaitparams.swingpercent);
		x = -percentBack * gaitparams.steplength + gaitparams.steplength / 2.0 + gaitparams.x_offset;
		z = gaitparams.Down_Amp * sin(PI * percentBack) + gaitparams.stanceheight;
	}
	leg_all.leg[gaitparams.i].x = x;
	leg_all.leg[gaitparams.i].z = z;
	//printf("x:%f,z:%f\n", x, z);
}

void IMU_Pos_Cal(double yaw, double pitch, double roll)
{
	standheight[0] =
		StandHeight * cos(pitch) * cos(roll);
	standheight[1] =
		StandHeight * cos(pitch) * cos(roll);
	standheight[2] =
		StandHeight * cos(pitch) * cos(roll);
	standheight[3] =
		StandHeight * cos(pitch) * cos(roll);
	x_offset[0] =
		-StandHeight * (cos(yaw) * sin(roll) - cos(roll) * sin(pitch) * sin(yaw));
	x_offset[1] =
		-StandHeight * (cos(yaw) * sin(roll) - cos(roll) * sin(pitch) * sin(yaw));
	x_offset[2] =
		-StandHeight * (cos(yaw) * sin(roll) - cos(roll) * sin(pitch) * sin(yaw));
	x_offset[3] =
		-StandHeight * (cos(yaw) * sin(roll) - cos(roll) * sin(pitch) * sin(yaw));

	constrain(standheight[0], 15, 24);
	constrain(standheight[1], 15, 24);
	constrain(standheight[2], 15, 24);
	constrain(standheight[3], 15, 24);
}
void CartesianToTheta_Cycloid(Leg* leg)
{
	leg->L = sqrt(leg->x * leg->x + leg->z * leg->z);
	if (leg->L < 11.5)
	{
		leg->x = leg->x * 11.5 / leg->L;
		leg->z = leg->z * 11.5 / leg->L;
		leg->L = 11.5;
	}
	if (leg->L > 31.0)
	{
		leg->x = leg->x * 31.0 / leg->L;
		leg->z = leg->z * 31.0 / leg->L;
		leg->L = 31.0;
	}
	leg->offset_A = asin(leg->x / leg->L_);
	leg->L_ = sqrt(-22.8925 + 0.93 * leg->L * leg->L);
	leg->sita3 = acos((leg->L_ * leg->L_ + leg->L * leg->L - dl * dl) / (2 * leg->L_ * leg->L));
	leg->alpha = acos((L1 * L1 + leg->L_ * leg->L_ - L2 * L2) / (2 * leg->L_ * L1));
	leg->sita1 = PI / 2 - (leg->alpha - leg->sita3) - leg->offset_A;
	leg->sita2 = -(PI / 2 - (leg->alpha + leg->sita3)) - leg->offset_A;
}
//逆解所有腿
void CartesianToTheta_Cycloid_All_Legs(void)
{
	CartesianToTheta_Cycloid(&leg_all.leg[0]);
	CartesianToTheta_Cycloid(&leg_all.leg[1]);
	CartesianToTheta_Cycloid(&leg_all.leg[2]);
	CartesianToTheta_Cycloid(&leg_all.leg[3]);
}
// 设置相关摆动角
void Angle_Setting(int Legid)
{
	switch (Legid)
	{
	case 0:
		Motor_Pos_out[0] = leg_all.leg[0].sita2;
		Motor_Pos_out[1] = leg_all.leg[0].sita1;
		break;
	case 1:
		Motor_Pos_out[2] = leg_all.leg[1].sita1;
		Motor_Pos_out[3] = leg_all.leg[1].sita2;
		break;
	case 2:
		Motor_Pos_out[4] = leg_all.leg[2].sita2;
		Motor_Pos_out[5] = leg_all.leg[2].sita1;
		break;
	case 3:
		Motor_Pos_out[6] = leg_all.leg[3].sita1;
		Motor_Pos_out[7] = leg_all.leg[3].sita2;
		break;

	}
}
// 移动腿函数
void Moveleg(void)
{
	Angle_Setting(0);  // 设置第 0 条腿的角度
	Angle_Setting(1);  // 设置第 1 条腿的角度
	Angle_Setting(2);  // 设置第 2 条腿的角度
	Angle_Setting(3);  // 设置第 3 条腿的角度
}
void Stand(void)
{
	for (int i = 0; i < 4; i++)
	{
		leg_all.leg[i].x = x_offset[i];
		leg_all.leg[i].z = standheight[i];
	}

	CartesianToTheta_Cycloid_All_Legs();
	Moveleg();

}