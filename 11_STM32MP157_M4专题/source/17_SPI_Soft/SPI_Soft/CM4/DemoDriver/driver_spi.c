/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 *
 * �ļ����ƣ�driver_spi.c
 * ժҪ��
 *
 * �޸���ʷ     �汾��       Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/
#include "driver_spi.h"
#include "driver_tim.h"

#define SPI_Delay()		us_timer_delay(50)

/*
 *  ��������void SPI_Init(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã���ʼ��SPI���ĸ�����
*/
void SPI_Init(void)
{
	SPI_CS(1);      // CS��ʼ����
	SPI_CLK(0);     // CLK��ʼ����
}

/*
 *  ��������void SPI_WriteByte(uint8_t data)
 *  ���������data -> Ҫд������
 *  �����������
 *  ����ֵ����
 *  �������ã�ģ��SPIдһ���ֽ�
*/
void SPI_WriteByte(uint8_t data)
{
    uint8_t i = 0;
    uint8_t temp = 0;

    for(i=0; i<8; i++)
    {
        temp = data&0x80;
        data = data<<1;

        SPI_CLK(0);
        SPI_MOSI(temp);
        SPI_Delay();
        SPI_CLK(1);
        SPI_Delay();
    }
}

/*
 *  ��������uint8_t SPI_ReadByte(void)
 *  ���������
 *  �����������
 *  ����ֵ������������
 *  �������ã�ģ��SPI��һ���ֽ�
*/
uint8_t SPI_ReadByte(void)
{
    uint8_t i = 0;
    uint8_t read_data = 0xFF;

    for(i=0; i<8; i++)
    {
        read_data = read_data << 1;

        SPI_CLK(0);
        SPI_Delay();
        SPI_CLK(1);
        SPI_Delay();
        if(SPI_MISO()==1)
        {
            read_data = read_data + 1;
        }
    }
    SPI_CLK(0);
    return read_data;
}

/*
 *  ��������uint8_t SPI_WriteReadByte(uint8_t pdata)
 *  ���������pdata -> Ҫд��һ���ֽ�����
 *  �����������
 *  ����ֵ������������
 *  �������ã�ģ��SPI��дһ���ֽ�
*/
uint16_t SPI_WriteReadByte(uint16_t pdata)
{
    uint8_t i = 0;
    uint8_t temp = 0;
    uint16_t read_data = 0xFFFF;

    for(i=0;i<16;i++)
    {
        temp = ((pdata&0x8000)==0x8000)? 1:0;
        pdata = pdata<<1;
        read_data = read_data<<1;

        SPI_CLK(0);
        SPI_MOSI(temp);
        SPI_Delay();
        SPI_CLK(1);
        SPI_Delay();
        if(SPI_MISO()==1)
        {
            read_data = read_data + 1;
        }
    }

    return read_data;
}
