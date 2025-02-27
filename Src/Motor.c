#include <Motor.h>
WbDeviceTag pos[8] = { 0 };
WbDeviceTag motor[8] = { 0 };
double Motor_Velocity[8]; //获取当前速度值的缓冲区
double Motor_Angle[8]; //获取当前角度值
double Motor_Pos_out[8]; //输出角度缓存区(目标角度值）
double Motor_Vel_out[8] ; //输出速度缓存区
void Motor_Init(void)
{
	 motor[0] = wb_robot_get_device("motor_1");
	 motor[1] = wb_robot_get_device("motor_2");
	 motor[2] = wb_robot_get_device("motor_3");
	 motor[3] = wb_robot_get_device("motor_4");
	 motor[4] = wb_robot_get_device("motor_5");
	 motor[5] = wb_robot_get_device("motor_6");
	 motor[6] = wb_robot_get_device("motor_7");
	 motor[7] = wb_robot_get_device("motor_8");

	for (int i = 0; i < 8; i++)
	{
		wb_motor_set_position(motor[i], INFINITY);
		wb_motor_set_velocity(motor[i], 0);
	}
	
}
void Motor_Sensor_Disable(void)
{
	for (int i = 0; i < 8; i ++ )
	{
		wb_position_sensor_disable(pos[i]);
	}
}
void Motor_Sensor_Enable(void)
{
	for (int i = 0; i < 8; i++)
	{
		wb_position_sensor_enable(pos[i], Sampling_period);
	}
}

void Pos_Sensor_Init(void)
{
	 pos[0] = wb_robot_get_device("pos_1");
	 pos[1] = wb_robot_get_device("pos_2");
	 pos[2] = wb_robot_get_device("pos_3");
	 pos[3] = wb_robot_get_device("pos_4");
	 pos[4] = wb_robot_get_device("pos_5");
	 pos[5] = wb_robot_get_device("pos_6");
	 pos[6] = wb_robot_get_device("pos_7");
	 pos[7] = wb_robot_get_device("pos_8");
	
	 Motor_Sensor_Enable();
}

void Motor_Run(void)
{
	for (int i = 0; i < 8; i++)
	{
		wb_motor_set_position(motor[i], Motor_Pos_out[i]);
		wb_motor_set_velocity(motor[i], Motor_Vel_out[i]);
	/*	printf("Motor_Pos_out:%f\n", Motor_Pos_out[i]);
		printf("Motor_Vel_out:%f\n", Motor_Vel_out[i]);*/
		//wb_motor_set_velocity(motor[i],Max_Speed);
	}
}
	void Motor_Pid_Cal(void)
 {
	double target_vel[8];
	for (int i = 0; i < 8; i++)
	{
		Motor_Velocity[i] = wb_motor_get_velocity(motor[i]);
		Motor_Angle[i] = wb_position_sensor_get_value(pos[i]);
		target_vel[i] = PID_CAL(pos_pid, Motor_Pos_out[i], Motor_Angle[i]);
		Motor_Vel_out[i] = PID_CAL(vel_pid, target_vel[i], Motor_Velocity[i]);
	}
	Motor_Run();
}
