#include "pwm.h"

extern TIM_HandleTypeDef htim4;

void PWM_Start(void)
{
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
    CAMERA_PITCH = 1450;
    CAMERA_YAW   = 2450;
}
