#include "driver_tim.h"
#include "tim.h"


__IO uint16_t delay_end = 0; // ��ʱ��ɱ�־

/*
 *  ��������void us_timer_delay(uint32_t t)
 *  ���������t-��ʱʱ��us(��Χ:0~21,474,836us)
 *  �����������
 *  ����ֵ����
 *  �������ã���ʱ��ʵ�ֵ���ʱ��������ʱʱ��Ϊt us��Ϊ������ʱ�䣬������ʹ�üĴ����������û��ɶ����ֲ�鿴ÿ���Ĵ���ÿλ�ĺ���
*/
void us_timer_delay(uint32_t t)
{
	uint32_t counter = 0;
	uint32_t autoreload = 200*t-1;

	delay_end = 0;
	HAL_TIM_Base_Stop_IT(&htim5); // ��ֹͣTIM5����

	__HAL_TIM_SET_AUTORELOAD(&htim5, autoreload); // ���ü����Զ�����ֵ,ÿ200��Ϊ1us
	__HAL_TIM_SET_COUNTER(&htim5, counter); // ���ü�����ʼֵΪ0,������ʱ����counter�����ӵ�autoreload

	HAL_TIM_Base_Start_IT(&htim5); // ����TIM5����
	while(!delay_end);
}

/*
 *  ��������void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 *  ���������htim->��ʱ�����
 *  �����������
 *  �������ã�ÿ������һ���������ʱ��ᵽ���жϻص��������ڴ˺�����ֹͣ�������޸ı�־λ
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM5)
    {
    	HAL_TIM_Base_Stop_IT(&htim5); // ֹͣTIM5����
    	delay_end = 1;
    }
}
