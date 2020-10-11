#include "driver_dac.h"
#include "dac.h"

/*
 *  ��������void DAC_Start(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�����DAC_OUT2
 *
*/
void DAC_Start(void)
{
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_2);
}

/*
 *  ��������void DAC_Stop(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ֹͣDAC_OUT2
 *
*/
void DAC_Stop(void)
{
	HAL_DAC_Stop(&hdac1, DAC_CHANNEL_2);
}

/*
 *  ��������int8_t DAC_SetValue(uint16_t data)
 *  �����������
 *  �����������
 *  ����ֵ��0:��ȷ -1:�������÷�Χ -2:���ô���
 *  �������ã�����DAC���ֵ
 *
 */
int8_t DAC_SetValue(uint16_t data)
{
	if(data>=4096)
	{
		return -1;
	}
	if(HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_2, DAC_ALIGN_12B_R, data) != HAL_OK)
	{
		return -2;
	}
	DAC_Start(); // �������,ÿ���޸�ֵ����Ҫ����DAC

	return 0;
}

/*
 *  ��������void DAC_SetVoltage(float vol)
 *  �����������Ҫ���õ������ѹֵ
 *  �����������
 *  ����ֵ����
 *  �������ã�����DAC���ֵ
 *
 *ע��:�ο���ѹΪVREF_VALUE 3.3V
 */
void DAC_SetVoltage(float vol)
{
	if (vol > VREF_VALUE)
	{
		printf("\r Set voltage out of range \n");
		return;
	}

	DAC_SetValue(vol*4095/VREF_VALUE);
}
