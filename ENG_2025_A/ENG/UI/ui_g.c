//
// Created by RM UI Designer
// Static Edition
//

#include <string.h>

#include "ui_interface.h"

ui_5_frame_t ui_g_1_0;

ui_interface_line_t *ui_g_1_qianzuo = (ui_interface_line_t*)&(ui_g_1_0.data[0]);
ui_interface_line_t *ui_g_1_qianyou = (ui_interface_line_t*)&(ui_g_1_0.data[1]);
ui_interface_line_t *ui_g_1_qianhen = (ui_interface_line_t*)&(ui_g_1_0.data[2]);

void _ui_init_g_1_0() {
    for (int i = 0; i < 3; i++) {
        ui_g_1_0.data[i].figure_name[0] = 0;
        ui_g_1_0.data[i].figure_name[1] = 0;
        ui_g_1_0.data[i].figure_name[2] = i + 0;
        ui_g_1_0.data[i].operate_type = 1;
    }
    for (int i = 3; i < 5; i++) {
        ui_g_1_0.data[i].operate_type = 0;
    }

    ui_g_1_qianzuo->figure_type = 0;
    ui_g_1_qianzuo->operate_type = 1;
    ui_g_1_qianzuo->layer = 0;
    ui_g_1_qianzuo->color = 8;
    ui_g_1_qianzuo->start_x = 843;
    ui_g_1_qianzuo->start_y = 2;
    ui_g_1_qianzuo->width = 7;
    ui_g_1_qianzuo->end_x = 890;
    ui_g_1_qianzuo->end_y = 623;

    ui_g_1_qianyou->figure_type = 0;
    ui_g_1_qianyou->operate_type = 1;
    ui_g_1_qianyou->layer = 0;
    ui_g_1_qianyou->color = 8;
    ui_g_1_qianyou->start_x = 1332;
    ui_g_1_qianyou->start_y = 1;
    ui_g_1_qianyou->width = 7;
    ui_g_1_qianyou->end_x = 1086;
    ui_g_1_qianyou->end_y = 614;
	
	ui_g_1_qianhen->figure_type = 0;
    ui_g_1_qianhen->operate_type = 1;
    ui_g_1_qianhen->layer = 0;
    ui_g_1_qianhen->color = 3;
    ui_g_1_qianhen->start_x = 10;
    ui_g_1_qianhen->start_y = 94;
    ui_g_1_qianhen->width = 10;
    ui_g_1_qianhen->end_x = 1910;
    ui_g_1_qianhen->end_y = 94;


    ui_proc_5_frame(&ui_g_1_0);
    SEND_MESSAGE((uint8_t *) &ui_g_1_0, sizeof(ui_g_1_0));
}

void _ui_update_g_1_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_1_0.data[i].operate_type = 2;
    }

    ui_proc_5_frame(&ui_g_1_0);
    SEND_MESSAGE((uint8_t *) &ui_g_1_0, sizeof(ui_g_1_0));
}

void _ui_remove_g_1_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_1_0.data[i].operate_type = 3;
    }

    ui_proc_5_frame(&ui_g_1_0);
    SEND_MESSAGE((uint8_t *) &ui_g_1_0, sizeof(ui_g_1_0));
}


void ui_init_g_1() {
    _ui_init_g_1_0();
}

void ui_update_g_1() {
    _ui_update_g_1_0();
}

void ui_remove_g_1() {
    _ui_remove_g_1_0();
}

ui_2_frame_t ui_g_2_0;

ui_interface_line_t *ui_g_2_houzuo = (ui_interface_line_t*)&(ui_g_2_0.data[0]);
ui_interface_line_t *ui_g_2_houyou = (ui_interface_line_t*)&(ui_g_2_0.data[1]);

void _ui_init_g_2_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_2_0.data[i].figure_name[0] = 0;
        ui_g_2_0.data[i].figure_name[1] = 1;
        ui_g_2_0.data[i].figure_name[2] = i + 0;
        ui_g_2_0.data[i].operate_type = 1;
    }
    for (int i = 2; i < 2; i++) {
        ui_g_2_0.data[i].operate_type = 0;
    }

    ui_g_2_houzuo->figure_type = 0;
    ui_g_2_houzuo->operate_type = 1;
    ui_g_2_houzuo->layer = 0;
    ui_g_2_houzuo->color = 8;
    ui_g_2_houzuo->start_x = 414;
    ui_g_2_houzuo->start_y = 2;
    ui_g_2_houzuo->width = 7;
    ui_g_2_houzuo->end_x = 837;
    ui_g_2_houzuo->end_y = 474;

    ui_g_2_houyou->figure_type = 0;
    ui_g_2_houyou->operate_type = 1;
    ui_g_2_houyou->layer = 0;
    ui_g_2_houyou->color = 8;
    ui_g_2_houyou->start_x = 1082;
    ui_g_2_houyou->start_y = 1;
    ui_g_2_houyou->width = 7;
    ui_g_2_houyou->end_x = 950;
    ui_g_2_houyou->end_y = 468;


    ui_proc_2_frame(&ui_g_2_0);
    SEND_MESSAGE((uint8_t *) &ui_g_2_0, sizeof(ui_g_2_0));
}

void _ui_update_g_2_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_2_0.data[i].operate_type = 2;
    }

    ui_proc_2_frame(&ui_g_2_0);
    SEND_MESSAGE((uint8_t *) &ui_g_2_0, sizeof(ui_g_2_0));
}

void _ui_remove_g_2_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_2_0.data[i].operate_type = 3;
    }

    ui_proc_2_frame(&ui_g_2_0);
    SEND_MESSAGE((uint8_t *) &ui_g_2_0, sizeof(ui_g_2_0));
}


void ui_init_g_2() {
    _ui_init_g_2_0();
}

void ui_update_g_2() {
    _ui_update_g_2_0();
}

void ui_remove_g_2() {
    _ui_remove_g_2_0();
}

ui_5_frame_t ui_g_3_0;

ui_interface_line_t *ui_g_3_yinqian = (ui_interface_line_t*)&(ui_g_3_0.data[0]);
ui_interface_line_t *ui_g_3_yinzuo = (ui_interface_line_t*)&(ui_g_3_0.data[1]);
ui_interface_line_t *ui_g_3_yinyou = (ui_interface_line_t*)&(ui_g_3_0.data[2]);

void _ui_init_g_3_0() {
    for (int i = 0; i < 3; i++) {
        ui_g_3_0.data[i].figure_name[0] = 0;
        ui_g_3_0.data[i].figure_name[1] = 2;
        ui_g_3_0.data[i].figure_name[2] = i + 0;
        ui_g_3_0.data[i].operate_type = 1;
    }
    for (int i = 3; i < 5; i++) {
        ui_g_3_0.data[i].operate_type = 0;
    }

    ui_g_3_yinqian->figure_type = 0;
    ui_g_3_yinqian->operate_type = 1;
    ui_g_3_yinqian->layer = 0;
    ui_g_3_yinqian->color = 2;
    ui_g_3_yinqian->start_x = 816;
    ui_g_3_yinqian->start_y = 405;
    ui_g_3_yinqian->width = 4;
    ui_g_3_yinqian->end_x = 1118;
    ui_g_3_yinqian->end_y = 400;

    ui_g_3_yinzuo->figure_type = 0;
    ui_g_3_yinzuo->operate_type = 1;
    ui_g_3_yinzuo->layer = 0;
    ui_g_3_yinzuo->color = 2;
    ui_g_3_yinzuo->start_x = 948;
    ui_g_3_yinzuo->start_y = 401;
    ui_g_3_yinzuo->width = 4;
    ui_g_3_yinzuo->end_x = 946;
    ui_g_3_yinzuo->end_y = 297;

    ui_g_3_yinyou->figure_type = 0;
    ui_g_3_yinyou->operate_type = 1;
    ui_g_3_yinyou->layer = 0;
    ui_g_3_yinyou->color = 2;
    ui_g_3_yinyou->start_x = 972;
    ui_g_3_yinyou->start_y = 402;
    ui_g_3_yinyou->width = 4;
    ui_g_3_yinyou->end_x = 976;
    ui_g_3_yinyou->end_y = 295;


    ui_proc_5_frame(&ui_g_3_0);
    SEND_MESSAGE((uint8_t *) &ui_g_3_0, sizeof(ui_g_3_0));
}

void _ui_update_g_3_0() {
    for (int i = 0; i < 3; i++) {
        ui_g_3_0.data[i].operate_type = 2;
    }

    ui_proc_5_frame(&ui_g_3_0);
    SEND_MESSAGE((uint8_t *) &ui_g_3_0, sizeof(ui_g_3_0));
}

void _ui_remove_g_3_0() {
    for (int i = 0; i < 3; i++) {
        ui_g_3_0.data[i].operate_type = 3;
    }

    ui_proc_5_frame(&ui_g_3_0);
    SEND_MESSAGE((uint8_t *) &ui_g_3_0, sizeof(ui_g_3_0));
}


void ui_init_g_3() {
    _ui_init_g_3_0();
}

void ui_update_g_3() {
    _ui_update_g_3_0();
}

void ui_remove_g_3() {
    _ui_remove_g_3_0();
}

ui_1_frame_t ui_g_4_0;

ui_interface_round_t *ui_g_4_gk = (ui_interface_round_t*)&(ui_g_4_0.data[0]);

void _ui_init_g_4_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_4_0.data[i].figure_name[0] = 0;
        ui_g_4_0.data[i].figure_name[1] = 3;
        ui_g_4_0.data[i].figure_name[2] = i + 0;
        ui_g_4_0.data[i].operate_type = 1;
    }
    for (int i = 1; i < 1; i++) {
        ui_g_4_0.data[i].operate_type = 0;
    }

    ui_g_4_gk->figure_type = 2;
    ui_g_4_gk->operate_type = 1;
    ui_g_4_gk->layer = 0;
    ui_g_4_gk->color = 2;
    ui_g_4_gk->start_x = 934;
    ui_g_4_gk->start_y = 415;
    ui_g_4_gk->width = 4;
    ui_g_4_gk->r = 16;


    ui_proc_1_frame(&ui_g_4_0);
    SEND_MESSAGE((uint8_t *) &ui_g_4_0, sizeof(ui_g_4_0));
}

void _ui_update_g_4_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_4_0.data[i].operate_type = 2;
    }

    ui_proc_1_frame(&ui_g_4_0);
    SEND_MESSAGE((uint8_t *) &ui_g_4_0, sizeof(ui_g_4_0));
}

void _ui_remove_g_4_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_4_0.data[i].operate_type = 3;
    }

    ui_proc_1_frame(&ui_g_4_0);
    SEND_MESSAGE((uint8_t *) &ui_g_4_0, sizeof(ui_g_4_0));
}


void ui_init_g_4() {
    _ui_init_g_4_0();
}

void ui_update_g_4() {
    _ui_update_g_4_0();
}

void ui_remove_g_4() {
    _ui_remove_g_4_0();
}

ui_1_frame_t ui_g_again_0;

ui_interface_round_t *ui_g_again_again = (ui_interface_round_t*)&(ui_g_again_0.data[0]);

void _ui_init_g_again_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_again_0.data[i].figure_name[0] = 0;
        ui_g_again_0.data[i].figure_name[1] = 4;
        ui_g_again_0.data[i].figure_name[2] = i + 0;
        ui_g_again_0.data[i].operate_type = 1;
    }
    for (int i = 1; i < 1; i++) {
        ui_g_again_0.data[i].operate_type = 0;
    }

    ui_g_again_again->figure_type = 2;
    ui_g_again_again->operate_type = 1;
    ui_g_again_again->layer = 0;
    ui_g_again_again->color = 1;
    ui_g_again_again->start_x = 296;
    ui_g_again_again->start_y = 828;
    ui_g_again_again->width = 20;
    ui_g_again_again->r = 15;


    ui_proc_1_frame(&ui_g_again_0);
    SEND_MESSAGE((uint8_t *) &ui_g_again_0, sizeof(ui_g_again_0));
}

void _ui_update_g_again_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_again_0.data[i].operate_type = 2;
    }

    ui_proc_1_frame(&ui_g_again_0);
    SEND_MESSAGE((uint8_t *) &ui_g_again_0, sizeof(ui_g_again_0));
}

void _ui_remove_g_again_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_again_0.data[i].operate_type = 3;
    }

    ui_proc_1_frame(&ui_g_again_0);
    SEND_MESSAGE((uint8_t *) &ui_g_again_0, sizeof(ui_g_again_0));
}


void ui_init_g_again() {
    _ui_init_g_again_0();
}

void ui_update_g_again() {
    _ui_update_g_again_0();
}

void ui_remove_g_again() {
    _ui_remove_g_again_0();
}

ui_1_frame_t ui_g_close_0;

ui_interface_round_t *ui_g_close_close = (ui_interface_round_t*)&(ui_g_close_0.data[0]);

void _ui_init_g_close_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_close_0.data[i].figure_name[0] = 0;
        ui_g_close_0.data[i].figure_name[1] = 5;
        ui_g_close_0.data[i].figure_name[2] = i + 0;
        ui_g_close_0.data[i].operate_type = 1;
    }
    for (int i = 1; i < 1; i++) {
        ui_g_close_0.data[i].operate_type = 0;
    }

    ui_g_close_close->figure_type = 2;
    ui_g_close_close->operate_type = 1;
    ui_g_close_close->layer = 0;
    ui_g_close_close->color = 7;
    ui_g_close_close->start_x = 298;
    ui_g_close_close->start_y = 742;
    ui_g_close_close->width = 20;
    ui_g_close_close->r = 15;


    ui_proc_1_frame(&ui_g_close_0);
    SEND_MESSAGE((uint8_t *) &ui_g_close_0, sizeof(ui_g_close_0));
}

void _ui_update_g_close_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_close_0.data[i].operate_type = 2;
    }

    ui_proc_1_frame(&ui_g_close_0);
    SEND_MESSAGE((uint8_t *) &ui_g_close_0, sizeof(ui_g_close_0));
}

void _ui_remove_g_close_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_close_0.data[i].operate_type = 3;
    }

    ui_proc_1_frame(&ui_g_close_0);
    SEND_MESSAGE((uint8_t *) &ui_g_close_0, sizeof(ui_g_close_0));
}


void ui_init_g_close() {
    _ui_init_g_close_0();
}

void ui_update_g_close() {
    _ui_update_g_close_0();
}

void ui_remove_g_close() {
    _ui_remove_g_close_0();
}

ui_1_frame_t ui_g_die_0;

ui_interface_round_t *ui_g_die_die = (ui_interface_round_t*)&(ui_g_die_0.data[0]);

void _ui_init_g_die_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_die_0.data[i].figure_name[0] = 0;
        ui_g_die_0.data[i].figure_name[1] = 6;
        ui_g_die_0.data[i].figure_name[2] = i + 0;
        ui_g_die_0.data[i].operate_type = 1;
    }
    for (int i = 1; i < 1; i++) {
        ui_g_die_0.data[i].operate_type = 0;
    }

    ui_g_die_die->figure_type = 2;
    ui_g_die_die->operate_type = 1;
    ui_g_die_die->layer = 0;
    ui_g_die_die->color = 7;
    ui_g_die_die->start_x = 296;
    ui_g_die_die->start_y = 828;
    ui_g_die_die->width = 20;
    ui_g_die_die->r = 15;


    ui_proc_1_frame(&ui_g_die_0);
    SEND_MESSAGE((uint8_t *) &ui_g_die_0, sizeof(ui_g_die_0));
}

void _ui_update_g_die_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_die_0.data[i].operate_type = 2;
    }

    ui_proc_1_frame(&ui_g_die_0);
    SEND_MESSAGE((uint8_t *) &ui_g_die_0, sizeof(ui_g_die_0));
}

void _ui_remove_g_die_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_die_0.data[i].operate_type = 3;
    }

    ui_proc_1_frame(&ui_g_die_0);
    SEND_MESSAGE((uint8_t *) &ui_g_die_0, sizeof(ui_g_die_0));
}


void ui_init_g_die() {
    _ui_init_g_die_0();
}

void ui_update_g_die() {
    _ui_update_g_die_0();
}

void ui_remove_g_die() {
    _ui_remove_g_die_0();
}

ui_1_frame_t ui_g_ok_0;

ui_interface_round_t *ui_g_ok_ok = (ui_interface_round_t*)&(ui_g_ok_0.data[0]);

void _ui_init_g_ok_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_ok_0.data[i].figure_name[0] = 0;
        ui_g_ok_0.data[i].figure_name[1] = 7;
        ui_g_ok_0.data[i].figure_name[2] = i + 0;
        ui_g_ok_0.data[i].operate_type = 1;
    }
    for (int i = 1; i < 1; i++) {
        ui_g_ok_0.data[i].operate_type = 0;
    }

    ui_g_ok_ok->figure_type = 2;
    ui_g_ok_ok->operate_type = 1;
    ui_g_ok_ok->layer = 0;
    ui_g_ok_ok->color = 2;
    ui_g_ok_ok->start_x = 296;
    ui_g_ok_ok->start_y = 828;
    ui_g_ok_ok->width = 20;
    ui_g_ok_ok->r = 15;


    ui_proc_1_frame(&ui_g_ok_0);
    SEND_MESSAGE((uint8_t *) &ui_g_ok_0, sizeof(ui_g_ok_0));
}

void _ui_update_g_ok_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_ok_0.data[i].operate_type = 2;
    }

    ui_proc_1_frame(&ui_g_ok_0);
    SEND_MESSAGE((uint8_t *) &ui_g_ok_0, sizeof(ui_g_ok_0));
}

void _ui_remove_g_ok_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_ok_0.data[i].operate_type = 3;
    }

    ui_proc_1_frame(&ui_g_ok_0);
    SEND_MESSAGE((uint8_t *) &ui_g_ok_0, sizeof(ui_g_ok_0));
}


void ui_init_g_ok() {
    _ui_init_g_ok_0();
}

void ui_update_g_ok() {
    _ui_update_g_ok_0();
}

void ui_remove_g_ok() {
    _ui_remove_g_ok_0();
}

ui_1_frame_t ui_g_open_0;

ui_interface_round_t *ui_g_open_open = (ui_interface_round_t*)&(ui_g_open_0.data[0]);

void _ui_init_g_open_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_open_0.data[i].figure_name[0] = 0;
        ui_g_open_0.data[i].figure_name[1] = 8;
        ui_g_open_0.data[i].figure_name[2] = i + 0;
        ui_g_open_0.data[i].operate_type = 1;
    }
    for (int i = 1; i < 1; i++) {
        ui_g_open_0.data[i].operate_type = 0;
    }

    ui_g_open_open->figure_type = 2;
    ui_g_open_open->operate_type = 1;
    ui_g_open_open->layer = 0;
    ui_g_open_open->color = 2;
    ui_g_open_open->start_x = 298;
    ui_g_open_open->start_y = 742;
    ui_g_open_open->width = 20;
    ui_g_open_open->r = 15;


    ui_proc_1_frame(&ui_g_open_0);
    SEND_MESSAGE((uint8_t *) &ui_g_open_0, sizeof(ui_g_open_0));
}

void _ui_update_g_open_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_open_0.data[i].operate_type = 2;
    }

    ui_proc_1_frame(&ui_g_open_0);
    SEND_MESSAGE((uint8_t *) &ui_g_open_0, sizeof(ui_g_open_0));
}

void _ui_remove_g_open_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_open_0.data[i].operate_type = 3;
    }

    ui_proc_1_frame(&ui_g_open_0);
    SEND_MESSAGE((uint8_t *) &ui_g_open_0, sizeof(ui_g_open_0));
}


void ui_init_g_open() {
    _ui_init_g_open_0();
}

void ui_update_g_open() {
    _ui_update_g_open_0();
}

void ui_remove_g_open() {
    _ui_remove_g_open_0();
}


ui_string_frame_t ui_g_pumg_0;
ui_interface_string_t* ui_g_pumg_pumg = &(ui_g_pumg_0.option);

void _ui_init_g_pumg_0() {
    ui_g_pumg_0.option.figure_name[0] = 0;
    ui_g_pumg_0.option.figure_name[1] = 9;
    ui_g_pumg_0.option.figure_name[2] = 0;
    ui_g_pumg_0.option.operate_type = 1;

    ui_g_pumg_pumg->figure_type = 7;
    ui_g_pumg_pumg->operate_type = 1;
    ui_g_pumg_pumg->layer = 0;
    ui_g_pumg_pumg->color = 4;
    ui_g_pumg_pumg->start_x = 68;
    ui_g_pumg_pumg->start_y = 780;
    ui_g_pumg_pumg->width = 4;
    ui_g_pumg_pumg->font_size = 40;
    ui_g_pumg_pumg->str_length = 4;
    strcpy(ui_g_pumg_pumg->string, "PUMG");


    ui_proc_string_frame(&ui_g_pumg_0);
    SEND_MESSAGE((uint8_t *) &ui_g_pumg_0, sizeof(ui_g_pumg_0));
}

void _ui_update_g_pumg_0() {
    ui_g_pumg_0.option.operate_type = 2;

    ui_proc_string_frame(&ui_g_pumg_0);
    SEND_MESSAGE((uint8_t *) &ui_g_pumg_0, sizeof(ui_g_pumg_0));
}

void _ui_remove_g_pumg_0() {
    ui_g_pumg_0.option.operate_type = 3;

    ui_proc_string_frame(&ui_g_pumg_0);
    SEND_MESSAGE((uint8_t *) &ui_g_pumg_0, sizeof(ui_g_pumg_0));
}

void ui_init_g_pumg() {
    _ui_init_g_pumg_0();
}

void ui_update_g_pumg() {
    _ui_update_g_pumg_0();
}

void ui_remove_g_pumg() {
    _ui_remove_g_pumg_0();
}


ui_string_frame_t ui_g_shijue_0;
ui_interface_string_t* ui_g_shijue_shijue = &(ui_g_shijue_0.option);

void _ui_init_g_shijue_0() {
    ui_g_shijue_0.option.figure_name[0] = 0;
    ui_g_shijue_0.option.figure_name[1] = 10;
    ui_g_shijue_0.option.figure_name[2] = 0;
    ui_g_shijue_0.option.operate_type = 1;

    ui_g_shijue_shijue->figure_type = 7;
    ui_g_shijue_shijue->operate_type = 1;
    ui_g_shijue_shijue->layer = 0;
    ui_g_shijue_shijue->color = 6;
    ui_g_shijue_shijue->start_x = 13;
    ui_g_shijue_shijue->start_y = 867;
    ui_g_shijue_shijue->width = 4;
    ui_g_shijue_shijue->font_size = 40;
    ui_g_shijue_shijue->str_length = 6;
    strcpy(ui_g_shijue_shijue->string, "Vision");


    ui_proc_string_frame(&ui_g_shijue_0);
    SEND_MESSAGE((uint8_t *) &ui_g_shijue_0, sizeof(ui_g_shijue_0));
}

void _ui_update_g_shijue_0() {
    ui_g_shijue_0.option.operate_type = 2;

    ui_proc_string_frame(&ui_g_shijue_0);
    SEND_MESSAGE((uint8_t *) &ui_g_shijue_0, sizeof(ui_g_shijue_0));
}

void _ui_remove_g_shijue_0() {
    ui_g_shijue_0.option.operate_type = 3;

    ui_proc_string_frame(&ui_g_shijue_0);
    SEND_MESSAGE((uint8_t *) &ui_g_shijue_0, sizeof(ui_g_shijue_0));
}

void ui_init_g_shijue() {
    _ui_init_g_shijue_0();
}

void ui_update_g_shijue() {
    _ui_update_g_shijue_0();
}

void ui_remove_g_shijue() {
    _ui_remove_g_shijue_0();
}

