#include "Eng_Task.h"

extern frame_t frame;
extern uint8_t Break_While_ctrl;
extern uint8_t ShiJue_mode_ctrl;
extern nuc_receive_data_t	nuc_receive_data;
extern int action_Num;

// AC板串口通信
void TransmitTask(void const *argument)
{
    usart_dma_init();
    sync_data_to_c_init();
    Robot_Custom_Data_Transmit_Init();
    while (1) {

        // 发送数据到C板 串口6
        HAL_UART_Transmit_DMA(&huart6, sync_data_to_c.bytes, SYNC_TO_C_SIZE);
        osDelay(17);

        // 通过图传链路给自定义控制器
        Robot_Custom_Data_Transmit();
        osDelay(17);
    }
}

void usb_task(void *argument)
{
	cmd_id_init();
	cmd_id_task_create(0x14,999);
	while(1)
	{
//		Nuc_data_unpacked();
		if(ShiJue_mode_ctrl) 
		{
			memset(&nuc_receive_data, 0, sizeof(nuc_receive_data_t));
			action_Num = 0;
		}
		cmd_id_queue_handle();
		osDelay(100);
	}
}

extern bool lift_inited;
extern bool camera_lift_inited;
extern int16_t lift_moto_current_set[2];

uint8_t lift_power_less_flag = 0;
int32_t tuchuan_pitch_angle = 28;
int32_t tuchuan_yaw_angle = CAMERA_YAW_FORWARD;

extern uint8_t Eng_life;
extern uint8_t last_Eng_life;

// lift电机控制任务
void LiftTask(void const *argument)
{
    osDelay(1000);
    wd_init();
    camera_lift_reset();
    osDelay(2);
    arm_lift_reset();
    for (;;) {

        //if (lift_inited && camera_lift_inited) { // 确认已经触碰微动开关后
//		if(last_Eng_life == 0 && Eng_life == 1)
//		{
//			SetMotoCurrent(&hcan2, Back, 0, 0, 0, 0);
//            SetMotoCurrent(&hcan1, Back, 0, 0, 0, 0);
//		}
		
//        else if(last_Eng_life == 1 && Eng_life == 1){
            Arm_Lift_Ctrl();
            Camera_Lift_Ctrl();
            SetMotoCurrent(&hcan2, Back, lift_moto_current_set[0], 0, 0, 0);
            osDelay(1);
            SetMotoCurrent(&hcan1, Back, 0, lift_moto_current_set[1], 0, 0);
            osDelay(1);
//        }
		
		if(MTMotoState[0].angle < -180) MTMotoState[0].angle_desired = tuchuan_pitch_angle - 360;
		else MTMotoState[0].angle_desired = tuchuan_pitch_angle;
		
		MTSetMotoPosition_single(MT_Motor1_can_ID, 120, (int32_t)(MTMotoState[0].angle_desired * 100));
		osDelay(1);
		
		if(MTMotoState[1].angle < -180) MTMotoState[1].angle_desired = tuchuan_yaw_angle - 360;
		else MTMotoState[1].angle_desired = tuchuan_yaw_angle;
		
		MTSetMotoPosition_single(MT_Motor2_can_ID, 180, (int32_t)(MTMotoState[1].angle_desired * 100));
		osDelay(1);
		
        //}
    }
}

// extern int16_t chassis_speed_coefficient;

//void Arm_Ctrl_Task(void *argument)
//{
//    for (;;) {

//        osDelay(10);
//    }
//}
