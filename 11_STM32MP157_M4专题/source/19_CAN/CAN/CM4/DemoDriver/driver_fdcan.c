#include "driver_fdcan.h"
#include "fdcan.h"

CAN_RX_DATA can_rx_data;
FDCAN_TxHeaderTypeDef TxHeader;
FDCAN_RxHeaderTypeDef RxHeader;

/*
 * �˺������ý��յĹ�����
*/
void HAL_FDCAN_SetFilter(void)
{
	FDCAN_FilterTypeDef  sFilterConfig;
	/* ����CAN�Ĺ��������˴�ȫ�����գ��������� */
	sFilterConfig.IdType 		= FDCAN_STANDARD_ID;			// ��׼֡
	sFilterConfig.FilterIndex 	= 0;
	sFilterConfig.FilterType 	= FDCAN_FILTER_DUAL;
	sFilterConfig.FilterConfig 	= FDCAN_FILTER_TO_RXFIFO0;
	sFilterConfig.FilterID1 = 0;	// ID1��ID2������0��ʾ�����н��ղ�������
	sFilterConfig.FilterID2 = 0;
	if (HAL_FDCAN_ConfigFilter(&hfdcan2, &sFilterConfig) != HAL_OK)
	{
		Error_Handler();
	}

	sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO1;
	if (HAL_FDCAN_ConfigFilter(&hfdcan2, &sFilterConfig) != HAL_OK)
	{
		Error_Handler();
	}

	if (HAL_FDCAN_Start(&hfdcan2) != HAL_OK)
	{
		Error_Handler();
	}

	// �������FIFO
	if(HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, FDCAN_IT_TX_COMPLETE) != HAL_OK)
	{
		Error_Handler();
	}
}

/*
 *  ��������void CAN_Transmit(uint16_t ID, uint8_t *pdata, uint8_t length)
 *  ���������ID    -> CAN���ͱ��ĵ�ID
 *            pdata -> ���ͱ��ĵ��׵�ַ
 *            length-> ���ͱ��ĵĸ��������8���ֽ�
 *  �����������
 *  ����ֵ����
 *  �������ã�CAN���ͺ���
*/
void CAN_Transmit(uint16_t ID, uint8_t *pdata, uint8_t length)
{
	TxHeader.Identifier 	= ID;					// ����ID
	TxHeader.IdType 		= FDCAN_STANDARD_ID;	// ����֡Ϊ��׼ID
	TxHeader.TxFrameType 	= FDCAN_DATA_FRAME;		// ������֡
	TxHeader.DataLength 	= FDCAN_DLC_BYTES_8;	// ������8���ֽ�
	TxHeader.ErrorStateIndicator 	= FDCAN_ESI_PASSIVE;
	TxHeader.BitRateSwitch 			= FDCAN_BRS_OFF;
	TxHeader.FDFormat 			= FDCAN_CLASSIC_CAN;// ��ͳCAN
	TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
	TxHeader.MessageMarker = 0;
	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader, pdata) != HAL_OK)
	{
		Error_Handler();
	}
}

volatile uint8_t rx_flag = 0;

void CAN_SetReceiveFlag(uint8_t flag)
{
	rx_flag = 0;
}

int8_t CAN_Receive(void)
{
	if(rx_flag==1)
	{
		rx_flag = 0;
		return 1;
	}

	return 0;
}

/*
 *  ��������void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *CanHandle)
 *  ���������CanHandle -> CAN���
 *  �����������
 *  ����ֵ����
 *  �������ã�CAN���ջص�����
*/
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
	/* Get RX message */
	if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, (uint8_t*)&can_rx_data.RX_Data[0]) != HAL_OK)
	{
		Error_Handler();
	}
	can_rx_data.ID = RxHeader.Identifier;
	can_rx_data.length = RxHeader.DataLength>>16;
	rx_flag = 1;
}
