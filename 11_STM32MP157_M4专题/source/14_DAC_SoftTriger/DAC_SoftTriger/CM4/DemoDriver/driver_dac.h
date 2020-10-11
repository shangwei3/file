#ifndef __DRIVER_DAC_H
#define __DRIVER_DAC_H

#include "main.h"

// ����ο���ѹ
#define VREF_VALUE  3.3
/*
 *  ��������void DAC_Start(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�����DAC
 *
*/
extern void DAC_Start(void);

/*
 *  ��������void DAC_Stop(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ֹͣDAC_OUT2
 *
*/
void DAC_Stop(void);

/*
 *  ��������int8_t DAC_SetValue(uint16_t data)
 *  �����������
 *  �����������
 *  ����ֵ��0:��ȷ -1:�������÷�Χ -2:���ô���
 *  �������ã�����DAC���ֵ
 *
 */
extern int8_t DAC_SetValue(uint16_t data);


/*
 *  ��������void DAC_SetVoltage(float vol)
 *  �����������Ҫ���õ������ѹֵ
 *  �����������
 *  ����ֵ����
 *  �������ã�����DAC���ֵ
 *
 *ע��:�ο���ѹΪVREF_VALUE 3.3V
 */
void DAC_SetVoltage(float vol);

#endif
