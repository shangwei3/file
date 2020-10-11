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
 *  ��������void Key1Polling(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ʹ����ѯ��ʽ��ѯ���Ƿ��£�ͨ�����¿��Ƶ�����
*/
static bool key1_flag = false;
void Key1Polling(void)
{
    if(READ_KEY1 == PUSH_DOWN)     // �����⵽��������
    {
    	HAL_Delay(5);               //  ��ʱ5ms����������
        if(READ_KEY1 == PUSH_DOWN) // ����������󰴼���Ȼ�Ǵ��ڱ����µ�״̬������Ϊ���������¹�
        {
        	key1_flag = !key1_flag; // ��һ����־λ���жϰ��������´���
        	if(key1_flag)
        	{
        		LED_GREEN_ON();
        	}
        	else
        	{
        		LED_GREEN_OFF();
        	}
        }
    }
}

/*
 *  ��������void Key2Polling(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ʹ����ѯ��ʽ��ѯ���Ƿ��£�ͨ�����¿��Ƶ�����
*/
static bool key2_flag = false;
void Key2Polling(void)
{
    if(READ_KEY2 == PUSH_DOWN)     // �����⵽��������
    {
        HAL_Delay(5);              // ��ʱ5ms����������
        if(READ_KEY2 == PUSH_DOWN) // ����������󰴼���Ȼ�Ǵ��ڱ����µ�״̬������Ϊ���������¹�
        {
        	key2_flag = !key2_flag; // ��һ����־λ���жϰ��������´���
        	if(key2_flag)
        	{
        		LED_YELLOW_ON();
        	}
        	else
        	{
        		LED_YELLOW_OFF();
        	}
        }
    }
}
