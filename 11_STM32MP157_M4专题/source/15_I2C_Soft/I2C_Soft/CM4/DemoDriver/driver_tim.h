#ifndef __DRIVER_TIM_H
#define __DRIVER_TIM_H

#include "main.h"

/*
 *  ��������void us_timer_delay(uint32_t t)
 *  ���������t-��ʱʱ��us(��Χ:0~21,474,836us)
 *  �����������
 *  ����ֵ����
 *  �������ã���ʱ��ʵ�ֵ���ʱ��������ʱʱ��Ϊt us��Ϊ������ʱ�䣬������ʹ�üĴ����������û��ɶ����ֲ�鿴ÿ���Ĵ���ÿλ�ĺ���
*/
extern void us_timer_delay(uint32_t t);

#endif
