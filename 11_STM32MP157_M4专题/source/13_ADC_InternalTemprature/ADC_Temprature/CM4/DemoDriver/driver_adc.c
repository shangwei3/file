#include "driver_adc.h"
#include "adc.h"

/*
 *  ��������int GetAdcAnlogValue(void)
 *  �����������
 *  �����������
 *  ����ֵ�����ز�������ģ���ѹ
 *  �������ã���ȡADC�Ĳ��������ڲ��¶�
 *
 *  ��ע���˴��ο���ѹΪ3.3V
*/
int GetTemptureValue(void)
{
	uint32_t nData = 0;
	uint16_t nValue = 0;

	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);  // �ȴ�ת����ɣ���ʱʱ��Ϊ100ms
	nData = HAL_ADC_GetValue(&hadc2);

	// 157�Ĳο���ѹΪ3.3V;����λ����16bit;
	nValue = __HAL_ADC_CALC_TEMPERATURE(3300UL, nData, ADC_RESOLUTION_16B);

	return nValue;
}
