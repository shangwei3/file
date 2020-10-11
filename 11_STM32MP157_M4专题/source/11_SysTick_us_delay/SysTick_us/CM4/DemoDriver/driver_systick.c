/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 * 
 * �ļ����ƣ�driver_systick.c
 * ժҪ��
 *  
 * �޸���ʷ     �汾��       Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/
#include "driver_systick.h"

/*
 * ȫ�ֱ�������
*/

static volatile uint32_t systick_t = 0;

/*
 *  ��������void SysTickInit(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã���ʼ��ϵͳ�δ�ʱ�ӵ�Ƶ�ʺ��ж����ȼ�
*/
void SysTickInit(void)
{
    uint32_t init_t = 0;

    init_t = SystemCoreClock/1000000;

	/* ʱ��(��λ:s)=1/Ƶ��(��λ:HZ)
	 * SystemCoreClockƵ��: 209MHz = 209,000,000
	 * ��MCU 1������209,000,000��
	 *       1us����� 209MHz/1000000 = 209��
	 * 209���ǵδ�ʱ�ӵĳ�ʼֵ,�����¼���209��,��������Ϊ0,�ͻ����һ���ж�
	 *
     * SystemCoreClock/1000:    1ms�ж�һ��
     * SystemCoreClock/100000:  10us�ж�һ��
     * SystemCoreClock/1000000: 1us�ж�һ��
    */
    if(HAL_SYSTICK_Config(init_t) != HAL_OK)
    {
        Error_Handler();
    }

    // ���õδ�ʱ���ж����ȼ������
    HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
    // ʹ�ܵδ�ʱ���ж�
    HAL_NVIC_EnableIRQ(SysTick_IRQn);
}

/*
 *  ��������void SysTickDelay(uint16_t u)
 *  ���������u-��ʱʱ��
 *  �����������
 *  ����ֵ����
 *  �������ã��δ�ʱ��ʵ�ֵ���ʱ����
*/
void SysTickDelay(uint32_t u)
{
    systick_t = u;
    while(systick_t != 0);
}

/*
 *  ��������void OwnSysTick_Handler(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã��δ�ʱ�����жϷ�����
*/
void OwnSysTick_Handler(void)
{
    if(systick_t != 0)
    {
        systick_t--;
    }
}
