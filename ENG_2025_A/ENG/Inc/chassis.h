#include "Includes.h"

#define KP_CHASSIS 20
#define KI_CHASSIS 0
#define KD_CHASSIS 0

#define KP_GIMBAL 20
#define KI_GIMBAL 0
#define KD_GIMBAL 0

#define MAX_MOVE_RMP	7700          //平移最大速度
#define MAX_ROTATE_RMP  4000   		  //自转最大速度
#define MOUSE_ROTATE_RMP 3000         //鼠标控制自转速度最大值
#define MOUSE_ROTATE_PARA 20          //鼠标控制自转系数

void chassis_pid_init(void);
void gimbal_pid_init(void);
void chassis_control_RC(void);

void MotoTask(void const * argument);