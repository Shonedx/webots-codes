#include "imu.h"
WbDeviceTag imu;
//void wb_inertial_unit_enable(WbDeviceTag tag, int sampling_period);
//void wb_inertial_unit_disable(WbDeviceTag tag);
//int wb_inertial_unit_get_sampling_period(WbDeviceTag tag);
//
//const double* wb_inertial_unit_get_roll_pitch_yaw(WbDeviceTag tag);
void Imu_Init(void)
{
	 imu = wb_robot_get_device("imu");
}

void Imu_Enable(void)
{
	wb_inertial_unit_enable(imu, Sampling_period);
}
void Imu_Disable(void)
{
	wb_inertial_unit_disable(imu);
}
const double* Imu_GetAngle(WbDeviceTag tag)
{
	wb_inertial_unit_get_roll_pitch_yaw(imu);
}