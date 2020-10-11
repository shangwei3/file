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
#include "driver_led.h"
#include "driver_key.h"

/*
 *  ��������void HAL_GPIO_EXTI_Callback(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã��ⲿ�жϴ������Ļص����������Դ���ͬ���Ŵ������жϷ������պ���
*/
static volatile bool key1_flag = false;           // ����һ��ȫ�־�̬��־�������жϰ������µĴ���
static volatile bool key2_flag = false;
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
		case KEY_USER1_Pin:
		{
			key1_flag = !key1_flag;
			if(key1_flag)
			{
				LED_GREEN_ON();
			}
			else
			{
				LED_GREEN_OFF();
			}
			break;
		}

		case KEY_USER2_Pin:
		{
			key2_flag = !key2_flag;
			if(key2_flag)
			{
				LED_YELLOW_ON();
			}
			else
			{
				LED_YELLOW_OFF();
			}
			break;
		}
		default:break;
	}
}
