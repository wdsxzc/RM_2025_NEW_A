#ifndef ROBOMASTER_PROTOCOL_H
#define ROBOMASTER_PROTOCOL_H

#include "struct_typedef.h"

#define HEADER_SOF 0xA5
#define REF_PROTOCOL_FRAME_MAX_SIZE         128

#define REF_PROTOCOL_HEADER_SIZE            sizeof(frame_header_t)
#define REF_PROTOCOL_CMD_SIZE               2
#define REF_PROTOCOL_CRC16_SIZE             2
#define REF_HEADER_CRC_LEN                  (REF_PROTOCOL_HEADER_SIZE + REF_PROTOCOL_CRC16_SIZE)
#define REF_HEADER_CRC_CMDID_LEN            (REF_PROTOCOL_HEADER_SIZE + REF_PROTOCOL_CRC16_SIZE + sizeof(uint16_t))
#define REF_HEADER_CMDID_LEN                (REF_PROTOCOL_HEADER_SIZE + sizeof(uint16_t))
  
#define INTERACTIV_DATA_HEADER_LEN           6
#define DATA_SET_LEN                         15
#define CHAR_LEN                   					 30
#define CHAR_DATA_TOTAL_LEN                  (INTERACTIV_DATA_HEADER_LEN + DATA_SET_LEN + CHAR_LEN)
#define DOUBLE_FIGURE_TOTAL_LEN 						 (INTERACTIV_DATA_HEADER_LEN + DATA_SET_LEN*2)

#pragma pack(push, 1)

typedef enum
{
  GAME_STATE_CMD_ID                 = 0x0001,
  GAME_RESULT_CMD_ID                = 0x0002,
  GAME_ROBOT_HP_CMD_ID              = 0x0003,
  FIELD_EVENTS_CMD_ID               = 0x0101,
  REFEREE_WARNING_CMD_ID            = 0x0104,
  ROBOT_STATE_CMD_ID                = 0x0201,
  POWER_HEAT_DATA_CMD_ID            = 0x0202,
  ROBOT_POS_CMD_ID                  = 0x0203,
  BUFF_MUSK_CMD_ID                  = 0x0204,
  ROBOT_HURT_CMD_ID                 = 0x0206,
  SHOOT_DATA_CMD_ID                 = 0x0207,
  BULLET_REMAINING_CMD_ID           = 0x0208,
  STUDENT_INTERACTIVE_DATA_CMD_ID   = 0x0301,
  CUSTOM_ROBOT_DATA_ID		        = 0x0302,
  ROBOT_CUSTOM_DATA_ID              = 0x0309,
  IDCustomData,
}referee_cmd_id_t;


typedef struct
{
  uint8_t SOF;
  uint16_t data_length;
  uint8_t seq;
  uint8_t CRC8;
} frame_header_t;

typedef enum
{
  DELETE_FIGURE        = 0x0100,
  DRAW_SINGLE_FIGURE   = 0x0101,
  DRAW_DOUBLE_FIGURE   = 0x0102,
  DRAW_FIVE_FIGURE     = 0x0103,
  DRAW_SEVEN_FIGURE    = 0x0104,
  DRAW_CHARACTER       = 0x0110,
}student_interactive_comment_id_t;

typedef enum
{
  STEP_HEADER_SOF  = 0,
  STEP_LENGTH_LOW  = 1,
  STEP_LENGTH_HIGH = 2,
  STEP_FRAME_SEQ   = 3,
  STEP_HEADER_CRC8 = 4,
  STEP_DATA_CRC16  = 5,
} unpack_step_e;

typedef struct
{
  frame_header_t *p_header;
  uint16_t       data_len;
  uint8_t        protocol_packet[REF_PROTOCOL_FRAME_MAX_SIZE];
  unpack_step_e  unpack_step;
  uint16_t       index;
} unpack_data_t;

#pragma pack(pop)

#endif //ROBOMASTER_PROTOCOL_H
