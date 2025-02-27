#include <Pid.h>
PidTypeDef pos_pid, vel_pid;

double constrain(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
// PID ���㺯��
double PID(double error, double* integral, double* prev_error, double Kp, double Ki, double Kd) {
    *integral += error * TIME_STEP / 1000.0; // ����
    double derivative = (error - *prev_error) / (TIME_STEP / 1000.0); // ΢��
    *prev_error = error; // ���浱ǰ���������һ�μ���
    return Kp * error + Ki * (*integral) + Kd * derivative; // PID ���
}
double PID_CAL(PidTypeDef pid,double tar_value, double cur_value)//PIDλ�û�
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
