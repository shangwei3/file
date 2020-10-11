#include "driver_wwdg.h"
#include "wwdg.h"

/*
 *  ��������void ClearIWDG(void)
 *  �����������
 *  �����������
 *  ����ֵ����
 *  �������ã�ˢ�¶������Ź��ļ��������׳�"ι��"
*/
void ClearWWDG(void)
{
    if (HAL_WWDG_Refresh(&hwwdg1) != HAL_OK)
    {
        Error_Handler();
    }
}

uint32_t TimeoutCalculation(uint32_t timevalue)
{
  uint32_t timeoutvalue = 0;
  uint32_t pclk1 = 0;
  uint32_t wdgtb = 0;

  /* considering APB divider is still 1, use HCLK value */
  pclk1 = HAL_RCC_GetPCLK1Freq();

  /* get prescaler */
  wdgtb = (1 << ((hwwdg1.Init.Prescaler) >> WWDG_CFR_WDGTB_Pos)); /* 2^WDGTB[1:0] */

  /* calculate timeout */
  timeoutvalue = ((4096 * wdgtb * timevalue) / (pclk1 / 1000));

  return timeoutvalue;
}
