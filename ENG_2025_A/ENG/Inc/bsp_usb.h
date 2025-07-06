#ifndef BSP_USB_H
#define BSP_USB_H

#include "main.h"
#include "string.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"

typedef struct{
	uint8_t usb_cdc_rx_buf[512];
	uint16_t usb_cdc_rx_len;
	uint8_t usb_cdc_rx_flag;
	uint8_t crc_cal;
	
	uint8_t usb_cdc_send_buf[512];
	
}usb_cdc_data_t;

extern usb_cdc_data_t usb_cdc_data;

void usb_init(void);
void usb_data_send(uint8_t *data,uint16_t len);

#endif

