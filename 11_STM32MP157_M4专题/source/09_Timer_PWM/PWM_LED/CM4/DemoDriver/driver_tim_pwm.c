#include "driver_tim_pwm.h"
#include "tim.h"

/*
 *	��������void TIM_LED3_PWM_Start(void)
 *	�����������
 *	�����������
 *	�������ã�������ʱ��
*/
void TIM_LED3_PWM_Start(void)
{
	if(HAL_TIM_Base_Start_IT(&htim2) != HAL_OK)
	{
		Error_Handler();
	}
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

/*
 *	��������void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 *	���������htim->��ʱ�����
 *	�����������
 *	�������ã�ÿ������һ���������ʱ��ᵽ���жϻص��������ڴ˺����ڸ���ռ�ձ�
*/
static uint16_t pulse = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2)
    {
    	pulse = pulse + 1;
    	if(pulse>=1000)
    	{
    		pulse = 0;
    	}
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
    }
}
