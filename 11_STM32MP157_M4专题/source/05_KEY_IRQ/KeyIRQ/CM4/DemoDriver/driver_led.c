/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 * 
 * �ļ����ƣ�driver_led.c
 * ժҪ��
 *  
 * �޸���ʷ     �汾��       Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/
#include "driver_led.h"

void DemoLedInit(void)
{
	/* LED��Ӧ�����ŵĳ�ʼ��,�Ѿ���STM32CubeMX��main.c�Զ����� */

	/* �����Ƴ�ʼ��״̬Ϊ�� */
	LED_GREEN_ON();
	LED_YELLOW_ON();
}

void LedBlinking(void)
{
	/* LED2(GREEN)��LED3(YELLOW)���1S��˸  */
	LED_GREEN_ON();
	LED_YELLOW_ON();
	HAL_Delay(1000);

	LED_GREEN_OFF();
	LED_YELLOW_OFF();
	HAL_Delay(1000);
}
