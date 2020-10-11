/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 *
 * �ļ����ƣ�driver_spi.h
 * ժҪ��
 *
 * �޸���ʷ     �汾��       Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/
#ifndef __DRIVER_SPI_H
#define __DRIVER_SPI_H

#include "main.h"

/************************* SPI Ӳ����ض��� *************************/

#define SPI_CLK(level)                   HAL_GPIO_WritePin(SPI5_CLK_GPIO_Port, SPI5_CLK_Pin, level&GPIO_PIN_SET)
#define SPI_MISO()                       HAL_GPIO_ReadPin(SPI5_MISO_GPIO_Port, SPI5_MISO_Pin)
#define SPI_MOSI(bit)                    HAL_GPIO_WritePin(SPI5_MOSI_GPIO_Port, SPI5_MOSI_Pin, bit&GPIO_PIN_SET)
#define SPI_CS(level)                    HAL_GPIO_WritePin(SPI5_NSS_GPIO_Port, SPI5_NSS_Pin, level&GPIO_PIN_SET)
/************************* SPI Ӳ����ض������ *************************/
/*
 *  ��������void SPI_Init(void)
 *  ���������
 *  �����������
 *  ����ֵ����
 *  �������ã���ʼ��SPI���ĸ�����
*/
extern void SPI_Init(void);

/*
 *  ��������uint8_t SPI_WriteReadByte(uint8_t pdata)
 *  ���������pdata -> Ҫд��һ���ֽ�����
 *  �����������
 *  ����ֵ������������
 *  �������ã�ģ��SPI��дһ���ֽ�
*/
extern uint16_t SPI_WriteReadByte(uint16_t pdata);

/*
 *  ��������void SPI_WriteByte(uint8_t data)
 *  ���������data -> Ҫд������
 *  �����������
 *  ����ֵ����
 *  �������ã�ģ��SPIдһ���ֽ�
*/
extern void SPI_WriteByte(uint8_t data);

/*
 *  ��������uint8_t SPI_ReadByte(void)
 *  ���������
 *  �����������
 *  ����ֵ������������
 *  �������ã�ģ��SPI��һ���ֽ�
*/
extern uint8_t SPI_ReadByte(void);

#endif  //__DRIVER_SPI_H
