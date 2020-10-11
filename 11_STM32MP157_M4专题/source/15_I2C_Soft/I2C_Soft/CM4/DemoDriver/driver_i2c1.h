/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 *
 * �ļ����ƣ�driver_I2C.h
 * ժҪ��
 *
 * �޸���ʷ     �汾��       Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/
#ifndef __DRIVER_I2C_H
#define __DRIVER_I2C_H

#include "main.h"

/************************* I2C Ӳ����ض��� *************************/
#define ACK             (1)
#define NACK            (0)

#define SCL_H()                 HAL_GPIO_WritePin(I2C1_SCL_GPIO_Port, I2C1_SCL_Pin, GPIO_PIN_SET)
#define SCL_L()                 HAL_GPIO_WritePin(I2C1_SCL_GPIO_Port, I2C1_SCL_Pin, GPIO_PIN_RESET)
#define SCL_INPUT()             HAL_GPIO_ReadPin(I2C1_SCL_GPIO_Port, I2C1_SCL_Pin)

#define SDA_H()                 HAL_GPIO_WritePin(I2C1_SDA_GPIO_Port, I2C1_SDA_Pin, GPIO_PIN_SET)
#define SDA_L()                 HAL_GPIO_WritePin(I2C1_SDA_GPIO_Port, I2C1_SDA_Pin, GPIO_PIN_RESET)
#define SDA_INPUT()             HAL_GPIO_ReadPin(I2C1_SDA_GPIO_Port, I2C1_SDA_Pin)
/************************* I2C Ӳ����ض������ *************************/
/*
 *  ��������void I2C_Init(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã���ʼ��ģ��I2C������Ϊ���״̬��SCL/SDA����ʼΪ�ߵ�ƽ
*/
extern void I2C_Init(void);

/*
 *  ��������void I2C_Start(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C��ʼ�ź�
*/
extern void I2C_Start(void);

/*
 *  ��������void I2C_Stop(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2Cֹͣ�ź�
*/
extern void I2C_Stop(void);

/*
 *  ��������void I2C_ACK(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C����Ӧ���ź�
*/
extern void I2C_ACK(void);

/*
 *  ��������void I2C_NACK(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C������Ӧ���ź�
*/
extern void I2C_NACK(void);

/*
 *  ��������uint8_t I2C_GetACK(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C�ȴ��ӻ���Ӧ���ź�
*/
extern uint8_t I2C_GetACK(void);

/*
 *  ��������void I2C_SendByte(uint8_t data)
 *  ���������data->���͵�����
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C����һ���ֽ�
*/
extern void I2C_SendByte(uint8_t data);

/*
 *  ��������uint8_t I2C_ReadByte(uint8_t ack)
 *  ���������ack->���͵�Ӧ���־��1Ӧ��0��Ӧ��
 *  �����������
 *  ����ֵ�����ض������ֽ�
 *  �������ã�I2C����һ���ֽ�
*/
extern uint8_t I2C_ReadByte(uint8_t ack);

#endif  //__DRIVER_I2C_H
