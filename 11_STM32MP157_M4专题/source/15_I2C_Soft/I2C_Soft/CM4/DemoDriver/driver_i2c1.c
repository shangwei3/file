/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 *
 * �ļ����ƣ�driver_I2C.c
 * ժҪ��
 *
 * �޸���ʷ     �汾��       Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/

#include "tim.h"
#include "driver_i2c1.h"
#include "driver_tim.h"

#define I2C_Delay()     us_timer_delay(5)

/*
 *  ��������void I2C_Init(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  ��������: SCL/SDA����ʼΪ�ߵ�ƽ
*/
void I2C_Init(void)
{
    SCL_H();
    SDA_H();
}

/*
 *  ��������static void I2C_SDA_OUT(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�����SDA����Ϊ���
*/
static void I2C_SDA_OUT(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;

    GPIO_InitStruct.Pin       = I2C1_SDA_Pin;
    HAL_GPIO_Init(I2C1_SDA_GPIO_Port, &GPIO_InitStruct);
}

/*
 *  ��������static void I2C_SDA_IN(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�����SDA����Ϊ����
*/
static void I2C_SDA_IN(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;

    GPIO_InitStruct.Pin       = I2C1_SDA_Pin;
    HAL_GPIO_Init(I2C1_SDA_GPIO_Port, &GPIO_InitStruct);
}

/*
 *  ��������void I2C_Start(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C��ʼ�ź�
*/
void I2C_Start(void)
{
    I2C_SDA_OUT();

    SCL_H();
	I2C_Delay();

    SDA_H();
    I2C_Delay();

    SDA_L();
    I2C_Delay();

    SCL_L();
    I2C_Delay();
}

/*
 *  ��������void I2C_Stop(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2Cֹͣ�ź�
*/
void I2C_Stop(void)
{
    I2C_SDA_OUT();

    SDA_L();
    I2C_Delay();

    SCL_H();
    I2C_Delay();

    SDA_H();
    I2C_Delay();
}

/*
 *  ��������void I2C_ACK(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C����Ӧ���ź�
*/
void I2C_ACK(void)
{
    I2C_SDA_OUT();

    SCL_L();
    I2C_Delay();

    SDA_L();
    I2C_Delay();

    SCL_H();
    I2C_Delay();

    SCL_L();
    I2C_Delay();
}

/*
 *  ��������void I2C_NACK(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C������Ӧ���ź�
*/
void I2C_NACK(void)
{
    I2C_SDA_OUT();

    SCL_L();
    I2C_Delay();

    SDA_H();
    I2C_Delay();

    SCL_H();
    I2C_Delay();

    SCL_L();
    I2C_Delay();
}

/*
 *  ��������uint8_t I2C_GetACK(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C�ȴ��ӻ���Ӧ���ź�
*/
uint8_t I2C_GetACK(void)
{
    uint8_t time = 0;
    I2C_SDA_IN();

    SCL_L();
	I2C_Delay();

    SDA_H();
	I2C_Delay();

	SCL_H();
	I2C_Delay();

    while(SDA_INPUT())
    {
        time++;
        if(time>250)
        {
            SCL_L();
            return 1;
        }
    }
    SCL_L();

    return 0;
}

/*
 *  ��������void I2C_SendByte(uint8_t data)
 *  ���������data->���͵�����
 *  �����������
 *  ����ֵ����
 *  �������ã�I2C����һ���ֽ�
*/
void I2C_SendByte(uint8_t data)
{
    uint8_t cnt = 0;

    I2C_SDA_OUT();

    for(cnt=0; cnt<8; cnt++)
    {
        SCL_L();
        I2C_Delay();

        if(data & 0x80)
        {
            SDA_H();
        }
        else
        {
            SDA_L();
        }
        data = data<<1;

        SCL_H();
        I2C_Delay();
    }

    SCL_L();
    I2C_Delay();
    I2C_GetACK();
}

/*
 *  ��������uint8_t I2C_ReadByte(uint8_t ack)
 *  ���������ack->���͵�Ӧ���־��1Ӧ��0��Ӧ��
 *  �����������
 *  ����ֵ�����ض������ֽ�
 *  �������ã�I2C����һ���ֽ�
*/
uint8_t I2C_ReadByte(uint8_t ack)
{
    uint8_t cnt;
    uint8_t data = 0xFF;
    I2C_SDA_IN();
    SCL_L();
    I2C_Delay();

    for(cnt=0; cnt<8; cnt++)
    {
        SCL_H();                 //SCL��(��ȡ����)
        I2C_Delay();

        data <<= 1;
        if(SDA_INPUT())
        {
            data |= 0x01;        //SDA��(������Ч)
        }
        SCL_L();
        I2C_Delay();
    }
    //����Ӧ���źţ�Ϊ�ʹ���Ӧ�𣬸ߴ����Ӧ��
    if(ack == 0)
    {
        I2C_NACK();
    }
    else
    {
        I2C_ACK();
    }
    return data;                 //��������
}


