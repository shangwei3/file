#ifndef __DRIVER_ADC_H
#define __DRIVER_ADC_H

#include "main.h"

extern void AdcStart(void);

/*
void GetAdcValue(uint16_t *pdatain, float *pdataout, uint16_t sz)
 *  ���������sz-��������
 *  ���������pdatain-���������ݴ洢���׵�ַ
 *  		pdataout-��ѹת�����洢���׵�ַ
 *  ����ֵ����
 *  �������ã���ȡADC�Ĳ�������ģ���ѹ֮
 *
 *  ��ע���˴��ο���ѹΪ3.3V
*/
extern void GetAdcValue(uint16_t *pdatain, float *pdataout, uint16_t sz);

#endif
