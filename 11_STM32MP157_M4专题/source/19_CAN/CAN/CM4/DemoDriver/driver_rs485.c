/*  Copyright (s) 2019 ���ڰ������Ƽ����޹�˾
 *  All rights reserved
 * 
 * �ļ����ƣ�driver_rs485.c
 * ժҪ��
 *  
 * �޸���ʷ     �汾��       Author       �޸�����
 *--------------------------------------------------
 * 2020.6.6      v01        ���ʿƼ�      �����ļ�
 *--------------------------------------------------
*/
#include "driver_rs485.h"
#include "usart.h"

static uint8_t rs485_rx_flag = 0;
volatile uint8_t rs485_tx_flag = 0;

void RS485_TX(uint8_t *pdata, uint8_t sz)
{
	rs485_tx_flag = 0;

	// RS485����Ϊ���
	DE_TX();

	// ��������
	HAL_UART_Transmit_IT(&huart6, (uint8_t*)pdata, sz);

	while(!RS485_GetTxFlag());
	// RS485����Ϊ����
	DE_RX();
}

void RS485_RX(uint8_t *pdata, uint8_t sz)
{
	rs485_rx_flag = 0;
	HAL_UART_Receive_IT(&huart6, pdata, sz);
}

uint8_t RS485_GetTxFlag(void)
{
	return rs485_tx_flag;
}

uint8_t RS485_GetRxFlag(void)
{
	return rs485_rx_flag;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART6)
	{
		rs485_rx_flag = 1;
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART6)
	{
		rs485_tx_flag = 1;
	}
}
