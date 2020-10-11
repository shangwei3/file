#ifndef __DRIVER_DMA_H
#define __DRIVER_DMA_H

#include "main.h"

extern __IO uint32_t transferErrorDetected;
extern __IO uint32_t transferCompleteDetected;

/*
 *  ��������void RegisterCallbackFunction(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ע��ص�����
*/
extern void RegisterCallbackFunction(void);

/*
 *  ��������void DMA_M2M_Start(uint32_t *srcAddr, uint32_t *dstAddr, uint16_t bufsz
 *  ���������srcAddr-����ԭ��ַ
 *            dstAddr-DMA���Ƶ�Ŀ�ĵ�ַ
 *            bufsz-DMA���Ƶ����ݴ�С����λ�ǳ�ʼ����ʱ��ѡ��ģ�byte,half-word,word
 *  �����������
 *  ����ֵ����
 *  �������ã���ʼ��DMA_Channel1������Ϊ�ڴ�-�ڴ�ģʽ��ÿ�ΰ���һ��word��4bytes
*/
extern void DMA_M2M_Start(uint32_t *srcAddr, uint32_t *dstAddr, uint16_t bufsz);

#endif
