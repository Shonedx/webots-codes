/*
 * File:          Dog.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <Dog.h>

/*
 * You may want to add macros here.
 */
void delay_ms(int milliseconds) {
    int steps = milliseconds / TIME_STEP;  // 计算需要的步数
    for (int i = 0; i < steps; i++) {
        wb_robot_step(TIME_STEP);  // 执行一次仿真步骤
    }
}
const double* roll_pitch_yaw;
extern WbDeviceTag imu;
  static double roll;
  static double yaw;
  static double pitch;
/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();
  Pid_Init();
  printf("pid Init\n");
  Motor_Init();
  printf("Motor Init\n");
  Pos_Sensor_Init();
  printf("PosSensor Init\n");
  Imu_Init();
  Imu_Enable();
  CTRL_Enable(Sampling_period);
  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */


  //w/*b_motor_set_position(motor[0], 3.14);
  //wb_motor_set_velocity(motor[0], 2);*/
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
      const double* roll_pitch_yaw = wb_inertial_unit_get_roll_pitch_yaw(imu);
      roll_pitch_yaw = Imu_GetAngle(imu);
      roll = roll_pitch_yaw[0];
      pitch = roll_pitch_yaw[1];
      yaw = roll_pitch_yaw[2];
      //printf("roll:%f pitch:%f yaw:%f\n", roll, pitch, yaw);
      /*if (currentstate != Stop || Jump)
      {
          IMU_Pos_Cal(yaw, pitch, -roll);
          Set_Standheight_Offset();
      }*/
     /*————控制——————*/
      CTRL();
      /*————执行对应步态———*/
      Gait();
      //Stand();
      Motor_Pid_Cal();
    /*——————————————————-*/
  
     /*
    * 
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
