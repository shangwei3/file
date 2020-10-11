#include "driver_adc.h"
#include "adc.h"
#include "dma.h"

volatile uint8_t conv_flag = 0;

void AdcStart(void)
{
	volatile uint16_t temp[100] = {0};
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)temp, 100);
}

/*
void GetAdcValue(uint16_t *pdatain, float *pdataout, uint16_t sz)
 *  ���������sz-��������
 *  ���������pdatain-���������ݴ洢���׵�ַ
 *  		 pdataout-��ѹת�����洢���׵�ַ
 *  ����ֵ����
 *  �������ã���ȡADC�Ĳ�������ģ���ѹ
 *
 *  ��ע���˴��ο���ѹΪ3.3V
*/
void GetAdcValue(uint16_t *pdatain, float *pdataout, uint16_t sz)
{
	uint16_t i = 0;
	conv_flag = 0;
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)pdatain, sz);
	while(conv_flag != 1);

	for(i=0; i<sz; i++)
	{
		pdataout[i] = pdatain[i] * 3.3 / 65536;
	}
}

/*
 *  ��������void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
 *  ���������hadc->adc���
 *  �����������
 *  �������ã�ÿ��ADCת����ɻᵽ���жϻص��������ڴ˺����ڸ�����ɱ�־
*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    if(hadc->Instance==ADC1)
    {
        conv_flag = 1;
    }
}
