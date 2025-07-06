#ifndef __PWM_H
#define __PWM_H
#include "main.h"
#include "Includes.h"

#define CAMERA_YAW_MAX 2500
#define CAMERA_YAW_MIN 500
#define CAMERA_YAW_STD 1500

#define CAMERA_PITCH_MAX 2500
#define CAMERA_PITCH_MIN 500
#define CAMERA_PITCH_STD 1500


#define CAMERA_PITCH TIM4->CCR1
#define CAMERA_YAW TIM4->CCR2

void PWM_Start(void);

#endif
