#include <JUMP.h>
double start_time = 0.0f;
extern int Jump_OK;

void Start_Jump(void)
{
    start_time = wb_robot_get_time();
}
void Execute_Jump(void)
{
    if (Jump_OK == 1)
    {
        double t = 1.5 * (wb_robot_get_time() - start_time);
        printf("t:%f start_time:%f\n", t, start_time);
        for (int i = 0; i < 4; i++) {
            if (t < 0.6) {

                 double x = -3.10;
                 double z = 11.59;
               /* double x = 12 * sin(-15.0f / 180.0f * 3.14);
                double z = 12 * cos(-15.0f / 180.0f * 3.14);*/
                leg_all.leg[i].x = x;
                leg_all.leg[i].z = z;
                //printf("waiting\n");
            }
            else if (t >= 0.6 && t < 1.0) {
                /*double x = 31 * sin(-60.f / 180.0f * 3.14);
                double z = 31 * cos(-60.f / 180.0f * 3.14);*/
                double x = -40.22;
                double z = 37.50;
                leg_all.leg[i].x = x;
                leg_all.leg[i].z = z;
                //printf("Jump!\n");

            }//&& t < 1.5
            else if (t >= 1.0 && t < 1.5) {

                double x = 0;
                double z = -17;
                leg_all.leg[i].x = x;
                leg_all.leg[i].z = z;
                //printf("fall!\n");
            }
            else {

                if (i == 3)
                {
                    Reset_start_time();
                    Jump_OK = 0;
                }
            }
        }
    }
   

}
void Reset_start_time(void) {
    start_time = wb_robot_get_time();
}
