/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 *
 * �ļ����ƣ�driver_key.h
 * ժҪ��
 *
 * �޸���ʷ     �汾��        Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/

#ifndef __DRIVER_KEY_H
#define __DRIVER_KEY_H

#include "main.h"

/*********************
 * ��������״̬����
**********************/
#define PUSH_DOWN                       GPIO_PIN_RESET
#define SPRING_UP                       GPIO_PIN_SET

/*********************
 * ���ź궨��
**********************/

/*********************
 * ����״̬��ȡ�����궨��
**********************/
#define READ_KEY1                  		HAL_GPIO_ReadPin(KEY_USER1_GPIO_Port, KEY_USER1_Pin)
#define READ_KEY2                		HAL_GPIO_ReadPin(KEY_USER2_GPIO_Port, KEY_USER2_Pin)


/*
 *  ��������void Key1Polling(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ʹ����ѯ��ʽ��ѯ���Ƿ��£�ͨ�����¿��Ƶ�����
*/
extern void Key1Polling(void);

/*
 *  ��������void Key2Polling(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ʹ����ѯ��ʽ��ѯ���Ƿ��£�ͨ�����¿��Ƶ�����
*/
extern void Key2Polling(void);

#endif
