#include "driver_dma.h"
#include "dma.h"

__IO uint32_t transferErrorDetected;
__IO uint32_t transferCompleteDetected;

static void TransferComplete(DMA_HandleTypeDef *DmaHandle);
static void TransferError(DMA_HandleTypeDef *DmaHandle);

/*
 *  ��������void RegisterCallbackFunction(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ע��ص�����
*/
void RegisterCallbackFunction(void)
{
	  // ע�ᴫ����ɺʹ������ص�����
	  HAL_DMA_RegisterCallback(&hdma_memtomem_dma2_stream0, HAL_DMA_XFER_CPLT_CB_ID, TransferComplete);
	  HAL_DMA_RegisterCallback(&hdma_memtomem_dma2_stream0, HAL_DMA_XFER_ERROR_CB_ID, TransferError);

	  // ����DMA���ж����ȼ�����ʹ��(��dma.c��MX_DMA_Init���Զ�����)
	  // HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
	  // HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}

/*
 *  ��������void TransferComplete(DMA_HandleTypeDef *DmaHandle)
 *  ���������DmaHandle-DMA���
 *  �����������
 *  ����ֵ����
 *  �������ã����DMA��������Ҳ������������ڴ˺�����������ɱ�־��һ
*/
static void TransferComplete(DMA_HandleTypeDef *DmaHandle)
{
  transferCompleteDetected = 1;
}

/*
 *  ��������void TransferError(DMA_HandleTypeDef *DmaHandle)
 *  ���������DmaHandle-DMA���
 *  �����������
 *  ����ֵ����
 *  �������ã����DMA��������з����������ڴ˺����н���������־��һ
*/
static void TransferError(DMA_HandleTypeDef *DmaHandle)
{
  transferErrorDetected = 1;
}

/*
 *  ��������void DMA_M2M_Start(uint32_t *srcAddr, uint32_t *dstAddr, uint16_t bufsz
 *  ���������srcAddr-����ԭ��ַ
 *            dstAddr-DMA���Ƶ�Ŀ�ĵ�ַ
 *            bufsz-DMA���Ƶ����ݴ�С����λ�ǳ�ʼ����ʱ��ѡ��ģ�byte,half-word,word
 *  �����������
 *  ����ֵ����
 *  �������ã���ʼ��DMA_Channel1������Ϊ�ڴ�-�ڴ�ģʽ��ÿ�ΰ���һ��word��4bytes
*/
void DMA_M2M_Start(uint32_t *srcAddr, uint32_t *dstAddr, uint16_t bufsz)
{
    if (HAL_DMA_Start_IT(&hdma_memtomem_dma2_stream0, (uint32_t)srcAddr, (uint32_t)dstAddr, bufsz) != HAL_OK)
    {
        Error_Handler();
    }
}

