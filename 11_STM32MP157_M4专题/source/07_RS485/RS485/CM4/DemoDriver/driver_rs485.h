/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 * 
 * �ļ����ƣ�driver_rs485.h
 * ժҪ��
 *  
 * �޸���ʷ     �汾��       Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/
#ifndef __DRIVER_RS485_H
#define __DRIVER_RS485_H

#include "main.h"
#include "stm32mp1xx_hal.h"

/********  Ӳ����غ궨�� ********/
#define DE_TX()	HAL_GPIO_WritePin(RS485_CTL_GPIO_Port, RS485_CTL_Pin, GPIO_PIN_SET)
#define DE_RX()	HAL_GPIO_WritePin(RS485_CTL_GPIO_Port, RS485_CTL_Pin, GPIO_PIN_RESET)

/********  �������� ********/


#endif
