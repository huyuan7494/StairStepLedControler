/*********************************���ݹ��������Ƽ����޹�˾*********************
  �ļ�: main.c
  ����: Zhengyu https://gzwelink.taobao.com
  �汾: V1.0.0
  ʱ��: 20210401
	ƽ̨:MINI-F030C8T6

*******************************************************************************/

#include "led.h"
                         
#define DBG_TIM1_DLY_1MS  1
#if DBG_TIM1_DLY_1MS
unsigned g_u32MsTick;
#endif
#define STAIRS_CNT   18
unsigned char g_au8Brightness[STAIRS_CNT];
unsigned g_u32Step;

void Delay_ms( uint16_t time_ms );

uint16_t TimerPeriod = 0;
#define TIMER_START(tim)  TIM_Cmd(tim,ENABLE);
#define AUTO_RELOAD_400ns   (19)    // 20.8333333 * 19 = 395.833333ns
#define AUTO_RELOAD_850ns   (41)    // 20.8333333 * 41 = 854.166653ns

//��ʱ������1ms
static void TIM1_Config(void)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;


  /* TIM1 clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 , ENABLE);
  
  /* Time Base configuration */
#if DBG_TIM1_DLY_1MS
  TIM_TimeBaseStructure.TIM_Prescaler = 47;   // 20.8333333 ns
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_Period = 999;    // 20.8333333 * 19 = 395.833333ns
#else
  TIM_TimeBaseStructure.TIM_Prescaler = 0;//47;   // 20.8333333 ns
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_Period = 19;//999;    // 20.8333333 * 19 = 395.833333ns
#endif
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	  /* Enable the TIM1 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_UP_TRG_COM_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	TIM_ITConfig(TIM1, TIM_IT_Update , ENABLE);
	// TIM_Cmd(TIM1,ENABLE);
 
}

unsigned u32Triggered(void)
{
    // TODO:
    return 0;
}

/**
  * @file   main
  * @brief  Main program.
  * @param  None
  * @retval None
  */
//ϵͳ��Ƶ48M,�ڲ�8M����
int main(void)
{
    unsigned u32LedOn = 0;

    LED_GPIO_Config();//��ʼ��LED�˿�
    SET_OE_PIN(1);
	  TIM1_Config();//��ʱ��1ms
    // TIM_SetAutoreload(TIM1, AUTO_RELOAD_400ns);
    TIM_SetAutoreload(TIM1, 60000);
    TIMER_START(TIM1);
    while(1)
    {	
        // Delay_ms(1);
        // if (!u32LedOn) {    // 灯没亮，检测一遍传感器输出信号
        //     if (u32Triggered) {
        //         u32LedOn = 1;
        //     }
        // } else {            // 亮灯过程中处理
        //     u32LedOn = u32LedProcess(g_u32Step++);
        // }
    }		
}

 /**
  * @file   Delay_ms
  * @brief  ������ʱtime_ms ms
  * @param   time_ms ��ʱʱ��
  * @retval ��
  */
void Delay_ms( uint16_t time_ms )
{
  uint16_t i,j;
  for( i=0;i<time_ms;i++ )
  {
		for( j=0;j<4784;j++ );
  }
}
