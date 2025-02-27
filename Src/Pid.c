#include <Pid.h>
PidTypeDef pos_pid, vel_pid;

double constrain(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
// PID 计算函数
double PID(double error, double* integral, double* prev_error, double Kp, double Ki, double Kd) {
    *integral += error * TIME_STEP / 1000.0; // 积分
    double derivative = (error - *prev_error) / (TIME_STEP / 1000.0); // 微分
    *prev_error = error; // 保存当前误差用于下一次计算
    return Kp * error + Ki * (*integral) + Kd * derivative; // PID 输出
}
double PID_CAL(PidTypeDef pid,double tar_value, double cur_value)//PID位置环
{
    pid.set = tar_value;
    pid.error[0] = pid.set - cur_value;
    pid.error[1] = pid.error[0] - pid.error[2];

    pid.Pout = pid.Kp * pid.error[0];
    pid.Iout += pid.Ki * pid.error[0]* (TIME_STEP / 1000.0);;
    pid.Dout = pid.Kd * pid.error[1] / (TIME_STEP / 1000.0);;

    pid.out = pid.Pout + pid.Iout + pid.Dout;
    if (fabs(pid.out) > fabs(pid.max_out))
    {
        pid.out = pid.max_out;
    }
    pid.error[2] = pid.error[0];
	
    return  pid.out;
}
void Pid_Init(void)
{
    pos_pid.Kd = 15;
    pos_pid.Kp = 0;
    pos_pid.Ki = 8;
    pos_pid.max_out = Max_Speed;
    vel_pid.Kd = 15;
    vel_pid.Kp = 0;
    vel_pid.Ki = 8;
    vel_pid.max_out = Max_Speed;
}
