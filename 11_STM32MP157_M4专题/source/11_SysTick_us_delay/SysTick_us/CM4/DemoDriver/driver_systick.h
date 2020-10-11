/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 *
 * �ļ����ƣ�driver_systick.h
 * ժҪ��
 *
 * �޸���ʷ     �汾��        Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/

#ifndef __DRIVER_SYSTICK_H
#define __DRIVER_SYSTICK_H

#include "main.h"
#include "stm32mp1xx_hal.h"


/*
 *  ��������void SysTickInit(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã���ʼ��ϵͳ�δ�ʱ�ӵ�Ƶ�ʺ��ж����ȼ�
*/
extern void SysTickInit(void);

/*
 *  ��������void SysTickDelay(uint16_t u)
 *  ���������u-��ʱʱ��
 *  �����������
 *  ����ֵ����
 *  �������ã��δ�ʱ��ʵ�ֵ���ʱ����
*/
extern void SysTickDelay(uint32_t u);

/*
 *  ��������void OwnSysTick_Handler(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã��δ�ʱ�����жϷ�����
*/
void OwnSysTick_Handler(void);

#endif
