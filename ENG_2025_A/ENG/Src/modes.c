#include "modes.h"

PoseMode posemod;
PoseMode last_posemod;
extern frame_t frame;
extern nuc_receive_data_t	nuc_receive_data;
extern int action_Num;
extern uint8_t t_UI;
extern uint8_t t_shijue;
int set_error_roll = 15;
uint8_t t_r = 0;


// 空模式
void None_Loop(void)
{
    frame.data.mode = 1;
    ROLL2           = 0.0f;
}

// 手动兑矿模式
void EXCHANGE_Loop(void)
{
    Custom_Robot_Ctrl();
}

void DEBUG_Loop(void)
{
    /*
        调试模式
    */
}

extern int32_t tuchuan_pitch_angle;
extern int32_t tuchuan_yaw_angle;

uint8_t Fetch_Two_Silver_ing = 0;
uint8_t Fetch_Left_Silver_ing = 0;
uint8_t Fetch_Right_Silver_ing = 0;
uint8_t Before_Exchange_Above_Silver_ing = 0;
uint8_t Before_Exchange_Below_Silver_ing = 0;
uint8_t Fetch_Ground_ing = 0;
uint8_t Fetch_Gold_ing = 0;
uint8_t Gold_To_Storage_ing = 0;
uint8_t Gold_To_DogHole_ing = 0;
uint8_t Gold_To_DogHole_Back_ing = 0;
uint8_t To_DogHole_ing = 0;
uint8_t To_DogHole_Back_ing = 0;
uint8_t SHIJUE_mode_ing = 0;
uint8_t ShiJue_mode_ctrl = 2;
uint8_t Break_While_ctrl = 0;
uint8_t SHIJUE_mode_arm = 0;
uint8_t xipan_debug_flag = 0;

void ModeTask(void const *argument)
{
    osDelay(500);
    Key_Init();
    for (;;) {
		
		if((RC_CtrlData.rc.sw2 == 3)&&(t_r == 0))
		{
			t_r = 1;
			sync_data_to_c.data.yaw1   = 0.0f;
			sync_data_to_c.data.pitch1 = -19.0f;
			sync_data_to_c.data.yaw2   = -18.0f;
			sync_data_to_c.data.roll1  = -180.0f;
			sync_data_to_c.data.pitch2 = 90.0f;
			sync_data_to_c.data.roll2  = 0.0f;
		}

        if (RC_CtrlData.rc.sw1 == 3) {
            Robot_Custom_Ctrl();
			
			if(Key_Check_Hold(&Keys.KEY_CTRL) && (RC_CtrlData.mouse.press_l == 1))
			{
				osDelay(20);
				LIFT = LIFT_MIN;
				YAW1 = 10;
				PITCH1 = 10;
				YAW2 = 70;
				ROLL1 = -180;
				PITCH2 = 80;
//				while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR  || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
//					osDelay(1);
//					Break_While
//				}
			}
		
			if(Key_Check_Hold(&Keys.KEY_CTRL) && RC_CtrlData.mouse.press_r == 1)
			{
				osDelay(20);
				LIFT = LIFT_MIN;
				YAW1 = -10;
				PITCH1 = 10;
				YAW2 = 110;
				ROLL1 = 0;
				PITCH2 = 80;
//				while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR  || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
//					osDelay(1);
//					Break_While
//				}
			}
			
        }

        else if (RC_CtrlData.rc.sw1 == 1) {
			if(RC_CtrlData.rc.sw2 == 3) tuchuan_pitch_angle = 28;
			else if(RC_CtrlData.rc.sw2 == 2) tuchuan_pitch_angle = 5;
			
            Custom_Robot_Ctrl();
        }

        else
		{
			tuchuan_pitch_angle = 28;
            frame.data.mode = 1;
		}

		if(RC_CtrlData.rc.sw1 != 1)
		{
			if (RC_CtrlData.rc.sw2 == 1) arm_xipan_open();
			if (RC_CtrlData.rc.sw2_last == 1 && RC_CtrlData.rc.sw2 == 3 && xipan_debug_flag == 0) 
			{
				arm_xipan_close();
				xipan_debug_flag = 1;
			}
		}
		
		

		//###################################################取银矿###################################################
		
        // 按下X,进入一键双银模式
        if ((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_X)) || Fetch_Two_Silver_ing == 1) {
            Fetch_Two_Silver_ing = 1;
            Before_Fetch_Right_Silver_Loop();

            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
            Fetch_Silver_To_Storage_Loop();
			
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			
			Before_Fetch_Left_Silver_Loop();
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			Fetch_Silver_OnTheOther_Silver_Loop();
			Fetch_Two_Silver_ing = 0;
        }
		
        // 按下Z,进入一键左银模式
        if ((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_Z)) || Fetch_Left_Silver_ing == 1) {
            Fetch_Left_Silver_ing = 1;
			
            Before_Fetch_Left_Silver_Loop();

            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
            Fetch_Silver_OnTheOther_Silver_Loop();
			
			Fetch_Left_Silver_ing = 0;
        }
		
        // 按下C,进入一键右银模式
        if ((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_C)) || Fetch_Right_Silver_ing == 1) {
            Fetch_Right_Silver_ing = 1;
			
            Before_Fetch_Right_Silver_Loop();

            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
            Fetch_Silver_OnTheOther_Silver_Loop();
			
			Fetch_Right_Silver_ing = 0;
        }
		//###################################################取银矿###################################################

		
		//###################################################取金矿###################################################
		// 按下A,进入一键金模式
        if ((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_A)) || Gold_To_Storage_ing == 1) {
            Gold_To_Storage_ing = 1;
            Before_Fetch_Gold_Loop();
			
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			
			LIFT = LIFT - 140000;
			PITCH2 = -20;
			osDelay(500);
			
            while (RC_CtrlData.mouse.press_l != 1) {
				LIFT -= RC_CtrlData.rc.ch2;
                osDelay(1);
            }
			
			Gold_To_Storage_ing = 0;
        }
				
		// 按下S,将矿放入矿仓
		if((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_S)) || Gold_To_Storage_ing == 1){
              Gold_To_Storage_ing = 1;
		
			  Fetch_Gold_To_Storage_Loop();
		
		      Gold_To_Storage_ing = 0;

		}
		
		// 按下D,带矿过狗洞姿态
		if((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_D) && (Key_Check_Hold(&Keys.KEY_SHIFT) == 0)) || Gold_To_DogHole_ing == 1){
            Gold_To_DogHole_ing = 1;
			
		
			Fetch_Gold_To_DogHole_Gesture_Loop();
			
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			CAMERA_LIFT = CAMERA_LIFT_MIN;
			
			tuchuan_pitch_angle = 0;
			osDelay(500);
			
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			
			tuchuan_pitch_angle = -25;
			CAMERA_LIFT = CAMERA_LIFT_STD;
		    Gold_To_DogHole_ing = 0;

		}
		
		// 按下F,带矿倒过狗洞姿态
		if(Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_F) && (Key_Check_Hold(&Keys.KEY_SHIFT) == 0) || Gold_To_DogHole_Back_ing == 1){
            Gold_To_DogHole_Back_ing = 1;
			
			Fetch_Gold_To_DogHole_Gesture_Loop();
			
			CAMERA_LIFT = CAMERA_LIFT_MIN;
			tuchuan_pitch_angle = 0;
			tuchuan_yaw_angle = CAMERA_YAW_BACK;
			t_UI = 2;
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			
			tuchuan_pitch_angle = -25;
			tuchuan_yaw_angle = CAMERA_YAW_FORWARD;
			CAMERA_LIFT = CAMERA_LIFT_STD;
			t_UI = 1;
			ui_remove_g_2();
			vTaskDelay(10);
			ui_remove_g_2();
			vTaskDelay(10);
			ui_remove_g_2();
			vTaskDelay(10);
			ui_remove_g_2();
			vTaskDelay(10);
			ui_remove_g_2();
			vTaskDelay(10);
		    Gold_To_DogHole_Back_ing = 0;

		}
		
		// 按下D,不带矿过狗洞姿态
		if((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_SHIFT) && Key_Check_Hold(&Keys.KEY_D)) || To_DogHole_ing == 1){
            To_DogHole_ing = 1;
			
		
			To_DogHole_Gesture_Loop();
			
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			CAMERA_LIFT = CAMERA_LIFT_MIN;
			
			tuchuan_pitch_angle = 0;
			osDelay(500);
			
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			
			tuchuan_pitch_angle = -25;
			CAMERA_LIFT = CAMERA_LIFT_STD;
		    To_DogHole_ing = 0;

		}
		
		// 按下F,不带矿倒过狗洞姿态
		if((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_SHIFT) && Key_Check_Hold(&Keys.KEY_F)) || To_DogHole_Back_ing == 1){
            To_DogHole_Back_ing = 1;
			
			To_DogHole_Gesture_Loop();
			
			CAMERA_LIFT = CAMERA_LIFT_MIN;
			tuchuan_pitch_angle = 0;
			tuchuan_yaw_angle = CAMERA_YAW_BACK;
			t_UI = 2;
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_1();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_4();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			ui_remove_g_3();
			vTaskDelay(10);
			
            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
			
			tuchuan_pitch_angle = -25;
			tuchuan_yaw_angle = CAMERA_YAW_FORWARD;
			CAMERA_LIFT = CAMERA_LIFT_STD;
			t_UI = 1;
			ui_remove_g_2();
			vTaskDelay(10);
			ui_remove_g_2();
			vTaskDelay(10);
			ui_remove_g_2();
			vTaskDelay(10);
			ui_remove_g_2();
			vTaskDelay(10);
			ui_remove_g_2();
			vTaskDelay(10);
		    To_DogHole_Back_ing = 0;

		}
		
		
		
		//###################################################取金矿###################################################

				
		//###################################################取地矿###################################################
		
        // 按下G,进入地矿模式
        if ((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_G)) || Fetch_Ground_ing == 1) {
            Fetch_Ground_ing = 1;
			
            Before_Fetch_Ground_Loop();

            while (RC_CtrlData.mouse.press_l != 1) {
                osDelay(1);
            }
            Fetch_Ground_Loop();
			
            while (RC_CtrlData.mouse.press_l != 1) {
				ROLL2 += RC_CtrlData.rc.ch2 * 0.001f;
                osDelay(1);
            }
			
			Fetch_Ground_ing = 0;
        }
		
		//###################################################取地矿###################################################
		
		
		
		//###################################################兑银矿###################################################

		// 按下V,准备兑上银矿
        if ((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_V)) || Before_Exchange_Above_Silver_ing == 1) {
            Before_Exchange_Above_Silver_ing = 1;
			
			Before_Exchange_Above_Silver_Loop();
			
			Before_Exchange_Above_Silver_ing = 0;
        }
		
		// 按下B,准备兑下银矿
        if ((Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_B)) || Before_Exchange_Below_Silver_ing == 1) {
            Before_Exchange_Below_Silver_ing = 1;
			
			Before_Exchange_Below_Silver_Loop();
			
			Before_Exchange_Below_Silver_ing = 0;
        }
		
		//###################################################兑银矿###################################################
		
				
				
		//##################################################视觉兑矿##################################################
		
        // 按下ctrl+e,进入视觉兑矿
        if ((SHIJUE_mode_ing == 1)||(Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_E))) {
            ShiJue_mode();
			SHIJUE_mode_ing = 0;
        }
		if ((SHIJUE_mode_arm == 1)||(Key_Check_Hold(&Keys.KEY_CTRL) && Key_Check_Hold(&Keys.KEY_W))) {
			LIFT = -600000;
            YAW1   = 0.0f;
			YAW2   = 0.0f;
			ROLL1  = 0.0f;
			ROLL2  = 0.0f;
			PITCH1 = 0.0f;
			PITCH2 = 0.0f;
			while (abs(LIFT - LIFT_READ) > LIFT_ERR_1 || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR_1 || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR_1 || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR_1 || fabsf(PITCH2 - PITCH2_READ) > DM_MOTO_ERR_1) {
					Break_While
					osDelay(1);
				}
			SHIJUE_mode_arm = 0;
        }
		
		//##################################################视觉兑矿##################################################
		
        osDelay(10);
    }
}

// ##################################################模式过程函数######################################################

// ########################################银矿########################################


// 取右矿,机械臂准备
void Before_Fetch_Right_Silver_Loop(void)
{
	ROLL2 = 0;
    LIFT = LIFT_SILVER_UP;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }

    YAW1   = -34.32f;
    YAW2   = 143.5f;
    ROLL1  = -109.0f;
    PITCH2 = 75.0f;
    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
			Break_While
    }
	
	PITCH1 = -19.81f;
    while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR) {
        osDelay(1);
			Break_While
    }
	
}

// 取左矿,机械臂准备
void Before_Fetch_Left_Silver_Loop(void)
{
	ROLL2 = 0;
    LIFT = LIFT_SILVER_UP;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
	
    YAW1   = 34.32f;
    YAW2   = 36.5f;
    ROLL1  = -71.0f;
    PITCH2 = 68.24f;

    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
			Break_While
    }
	
	PITCH1 = -19.81f;
    while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR) {
        osDelay(1);
			Break_While
    }
}


// 取银矿并放置于矿仓内
void Fetch_Silver_To_Storage_Loop(void)
{
    arm_xipan_open();

    LIFT = LIFT_SILVER_DOWN;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }

    LIFT = LIFT_SILVER_DOWN - 750000;

    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
	
    PITCH1 = 0.0f;

	while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
    }
	
	YAW1   = -63.0f;
    PITCH1 = 0.0f;
    YAW2   = -46.0f;
    ROLL1  = -90.0f;
    PITCH2 = 90.0f;
    ROLL2  = -40.0f;
	
	while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR || fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
    }
	
	LIFT = -460000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
	
	osDelay(100);
    arm_xipan_close();
	osDelay(1000);
	
    LIFT -= 100000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
	}
	
}

// 取银矿放在另一块矿上
void Fetch_Silver_OnTheOther_Silver_Loop(void)
{
    arm_xipan_open();

    LIFT = LIFT_SILVER_DOWN;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }

    LIFT = LIFT_SILVER_DOWN - 750000;

    while (abs(LIFT - LIFT_READ) > 5000) {
        osDelay(1);
			Break_While
    }
	
	YAW1   = -41.0f;
    PITCH1 = 0.0f;
    YAW2   = -50.0f;
    ROLL1  = -90.0f;
    PITCH2 = 0.0f;
	ROLL2  = 5.0f;
	
    while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR || fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
	}
	
    LIFT = -600000;
	
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }

}

// 取上银矿并准备兑换
void Before_Exchange_Above_Silver_Loop(void)
{
    arm_xipan_close();
	osDelay(1200);
	
	YAW1   = -15.0f;
    PITCH1 = 0.0f;
    YAW2   = -57.0f;
    ROLL1  = -90.0f;
    PITCH2 = 0.0f;
	ROLL2  = 0.0f;

    while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR || fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
	}

    LIFT = -950000;

    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
	
	arm_xipan_open();

	YAW1   = -70.0f;
    PITCH1 = 8.0f;
    YAW2   = -45.0f;
    ROLL1  = -90.0f;
    PITCH2 = 90.0f;
	
    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR  || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
	}
	
    LIFT += 250000;
	
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
	
    LIFT -= 250000;
	
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
	
	YAW1   = 0.0f;
    PITCH1 = 0.0f;
    YAW2   = 0.0f;
    ROLL1  = -90.0f;
    PITCH2 = 70.0f;
	ROLL2 += 180;
	
    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR  || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
	}
	
	PITCH1 = -10.0f;
	while(fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR)
	{
		osDelay(1);
		Break_While
	}
}


// 取下银矿并准备兑换
void Before_Exchange_Below_Silver_Loop(void)
{
    arm_xipan_close();
	osDelay(200);
	
    YAW1 = 0.0f;
    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR) {
        osDelay(1);
			Break_While
	}
	
    LIFT = -110000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
	}

	YAW1   = -30.0f;
    PITCH1 = 0.0f;
    YAW2   = -55.65f;
    ROLL1  = -73.0f;
    PITCH2 = 27.0f;

	arm_xipan_open();
	
    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR  || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
	}
	
	PITCH1 = -24.49f;
    while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR) {
        osDelay(1);
			Break_While
	}
	
	osDelay(150);
	YAW1   = -43.25f;
    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR) {
        osDelay(1);
			Break_While
    }
	osDelay(100);
	
	LIFT -= 350000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
	

	LIFT -= 600000;
	YAW1   = 0.0f;
	PITCH1 = -10.0f;
    YAW2   = 0.0f;
    ROLL1  = -90.0f;
    PITCH2 = 70.0f;
	ROLL2 -= 90;
	
    while (abs(LIFT - LIFT_READ) > LIFT_ERR || fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR  || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
	}
	
}

// ########################################地矿########################################


// 取地矿准备
void Before_Fetch_Ground_Loop(void)
{
    arm_xipan_open();
	
    LIFT = -450000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
	}

	YAW1   = 30.0f;
    PITCH1 = 0.0f;
    YAW2   = 30.0f;
    ROLL1  = -70.0f;
    PITCH2 = 75.f;
	
    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR  || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
	}
	
	PITCH1 = -20.0f;
    while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR) {
        osDelay(1);
			Break_While
	}

}


// 取地矿
void Fetch_Ground_Loop(void)
{
    LIFT = -200000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
	}
	osDelay(200);

	LIFT = -850000;
	YAW1   = 0.0f;
    PITCH1 = 0.0f;
	YAW2   = 0.0f;
    ROLL1  = -90.0f;
    PITCH2 = 90.0f;

    while (abs(LIFT - LIFT_READ) > LIFT_ERR || fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
	}
		


}

// 取金矿,机械臂准备
void Before_Fetch_Gold_Loop(void)
{
	arm_xipan_open();
	
    YAW1   = 0.0f;
	PITCH1 = 3.5f;
    YAW2   = 90.0f;
    ROLL1  = -90.0f;
	PITCH2 = 0.0f;
	ROLL2 = 0.0f;
    while (fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
		Break_While
    }
	
    LIFT = -30000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }	
	

}


// 放置于矿仓内
void Fetch_Gold_To_Storage_Loop(void)
{
    LIFT = -750000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
		PITCH2 = 90.0f;
		while (fabsf(PITCH2 - PITCH2_READ) > DM_MOTO_ERR)
		{
			osDelay(1);
			Break_While
		}
	
	YAW1   = -63.0f;
    PITCH1 = 0.0f;
    YAW2   = -46.0f;
    ROLL1  = -90.0f;
    ROLL2  += 68.0f;
	
	while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR || fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
				Break_While
    }
	
	LIFT = -460000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
    }
	
	osDelay(100);
    arm_xipan_close();
	osDelay(1000);
	
    LIFT -= 100000;
    while (abs(LIFT - LIFT_READ) > LIFT_ERR) {
        osDelay(1);
			Break_While
	}
	
}

// 带矿过狗洞姿态
void Fetch_Gold_To_DogHole_Gesture_Loop(void)
{
	
	LIFT = -50000;
	YAW1   = 0.0f;
    PITCH1 = 0.0f;
    YAW2   = -10.0f;
    ROLL1  = -145.0f;
    PITCH2 = 90.0f;
	ROLL2 += 0;
		
	while (abs(LIFT - LIFT_READ) > LIFT_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR || fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
	Break_While
    }
	
    PITCH1 = -19.0f;
	while (fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR){
        osDelay(1);
		Break_While
    }
}

//不带矿过狗洞
void To_DogHole_Gesture_Loop(void)
{
	PITCH1 = 0.0f;
	LIFT = -50000;
	while (abs(LIFT - LIFT_READ) > LIFT_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR) {
        osDelay(1);
	Break_While
    }
	
	YAW1   = -70.0f;
    YAW2   = -45.0f;
    ROLL1  = -145.0f;
    PITCH2 = 90.0f;
	ROLL2 += 0;
		
	while (abs(LIFT - LIFT_READ) > LIFT_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR || fabsf(YAW1 - YAW1_READ) > DM_MOTO_ERR || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR) {
        osDelay(1);
	Break_While
    }
	
	PITCH1 = -7.0f;
	LIFT = -50000;
	while (abs(LIFT - LIFT_READ) > LIFT_ERR || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR) {
        osDelay(1);
	Break_While
    }
}

//视觉兑矿
void ShiJue_mode()
{
	for(int i=0;i<=action_Num;i++)
	{
		if(nuc_receive_data.action_data[i].len > 0.11)
		{ 
			uint16_t tt = 0;
			LIFT 	 = nuc_receive_data.action_data[i].len / 0.43f * (-1299000.0f) - 1000.0f;
			YAW1   = nuc_receive_data.action_data[i].yaw1;
			PITCH1 = nuc_receive_data.action_data[i].pitch1 * (-1.0f) ;
			YAW2   = nuc_receive_data.action_data[i].yaw2 * (-1.0f) ;
			if(nuc_receive_data.action_data[i].roll1>45) ROLL1 = nuc_receive_data.action_data[i].roll1 - 360.0f;
			else if(nuc_receive_data.action_data[i].roll1<-315) ROLL1 = nuc_receive_data.action_data[i].roll1 + 360.0f;
			else ROLL1  = nuc_receive_data.action_data[i].roll1;
			PITCH2 = nuc_receive_data.action_data[i].pitch2;
			ROLL2  = nuc_receive_data.action_data[i].roll2 + set_error_roll;
			while (abs(LIFT - LIFT_READ) > LIFT_ERR_1 || fabsf(PITCH1 - PITCH1_READ) > DM_MOTO_ERR_1 || fabsf(YAW2 - YAW2_READ) > DM_MOTO_ERR_1 || fabsf(ROLL1 - ROLL1_READ) > DM_MOTO_ERR_1 || fabsf(PITCH2 - PITCH2_READ) > DM_MOTO_ERR_1) {
					Break_While
					tt++;
					if(tt == 300) break;
					osDelay(1);
				}
		}
	}
	memset(&nuc_receive_data, 0, sizeof(nuc_receive_data_t));
	action_Num = 0;
	t_shijue = 0;
}
