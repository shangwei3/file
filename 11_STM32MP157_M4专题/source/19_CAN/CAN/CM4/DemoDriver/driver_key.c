/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 *
 * �ļ����ƣ�driver_key.c
 * ժҪ��
 *
 * �޸���ʷ     �汾��        Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/
#include <stdbool.h>

#include "driver_key.h"


extern uint8_t test_flag;
/*
 *  ��������void HAL_GPIO_EXTI_Callback(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã��ⲿ�жϴ������Ļص����������Դ���ͬ���Ŵ������жϷ������պ���
*/
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
		case KEY_USER1_Pin:
		{
			break;
		}

		case KEY_USER2_Pin:
		{
			test_flag = 1;
			break;
		}
		default:break;
	}
}
