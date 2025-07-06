#include "includes.h"

void can_filter_init(void)
{

    CAN_FilterTypeDef CAN_FilterInitStructure_can1_fifo0; // 接收摄像头抬升和图传云台脉塔电机消息
    CAN_FilterTypeDef CAN_FilterInitStructure_can2_fifo1; // 接收底盘和机械臂抬升消息

    CAN_FilterInitStructure_can1_fifo0.FilterActivation     = ENABLE;                // 使能过滤器
    CAN_FilterInitStructure_can1_fifo0.FilterMode           = CAN_FILTERMODE_IDMASK; // 标识符屏蔽
    CAN_FilterInitStructure_can1_fifo0.FilterScale          = CAN_FILTERSCALE_32BIT;
    CAN_FilterInitStructure_can1_fifo0.FilterIdHigh         = 0x0000;
    CAN_FilterInitStructure_can1_fifo0.FilterIdLow          = 0x0000;
    CAN_FilterInitStructure_can1_fifo0.FilterMaskIdHigh     = 0x0000;
    CAN_FilterInitStructure_can1_fifo0.FilterMaskIdLow      = 0x0000;
    CAN_FilterInitStructure_can1_fifo0.FilterBank           = 0;            // 过滤器编号
    CAN_FilterInitStructure_can1_fifo0.FilterFIFOAssignment = CAN_RX_FIFO0; // 过滤器关联到FIFO0

    HAL_CAN_ConfigFilter(&hcan1, &CAN_FilterInitStructure_can1_fifo0);

    CAN_FilterInitStructure_can2_fifo1.FilterActivation     = ENABLE; // 使能过滤器
    CAN_FilterInitStructure_can2_fifo1.FilterMode           = CAN_FILTERMODE_IDMASK;
    CAN_FilterInitStructure_can2_fifo1.FilterScale          = CAN_FILTERSCALE_32BIT;
    CAN_FilterInitStructure_can2_fifo1.FilterIdHigh         = CAN_Motor_ALL_ID << 5;
    CAN_FilterInitStructure_can2_fifo1.FilterIdLow          = 0x0000;
    CAN_FilterInitStructure_can2_fifo1.FilterMaskIdHigh     = 0xFF00; // 0x200~0x208
    CAN_FilterInitStructure_can2_fifo1.FilterMaskIdLow      = 0x0000;
    CAN_FilterInitStructure_can2_fifo1.SlaveStartFilterBank = 14;
    CAN_FilterInitStructure_can2_fifo1.FilterBank           = 14;           // 过滤器编号
    CAN_FilterInitStructure_can2_fifo1.FilterFIFOAssignment = CAN_RX_FIFO1; // 过滤器关联到FIFO1

    HAL_CAN_ConfigFilter(&hcan2, &CAN_FilterInitStructure_can2_fifo1);

    // 使能can1 can2
    HAL_CAN_Start(&hcan1);
    HAL_CAN_Start(&hcan2);

    // 使能接收邮箱pending中断
    HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
    HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING);
}

/**
 * @brief          hal库CAN回调函数,接收电机原始数据
 * @param[in]      hcan:CAN句柄指针
 * @retval         none
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    SaveMotoMsg(&hcan1, CAN_RX_FIFO0); // 接收电机反馈消息
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    SaveMotoMsg(&hcan2, CAN_RX_FIFO1);
}
