/******************************************************************************
  �ļ�: led.c
  ����: Zhengyu https://gzwelink.taobao.com
  �汾: V1.0.0
  ʱ��: 20200401
	ƽ̨:MINI-G030C8T6

*******************************************************************************/


//ͷ�ļ�
#include "led.h"

 /**
  * @file   LED_GPIO_Config
  * @brief  LED����������
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{	
	//����һ��GPIO_InitTypeDef ���͵Ľṹ��
	GPIO_InitTypeDef  GPIO_InitStructure;
	//ʹ��GPIOC������ʱ��
	RCC_AHBPeriphClockCmd(LED1_GPIO_RCC,ENABLE);//ʹ��GPIO������ʱ��
	
	GPIO_InitStructure.GPIO_Pin =LED1_GPIO_PIN;	//ѡ��Ҫ�õ�GPIO����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	//��������Ϊ��ͨ���ģʽ				
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	//��������Ϊ�������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //��������Ϊ����		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//���������ٶ�Ϊ50MHZ
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);//���ÿ⺯������ʼ��GPIO

  // Contrl OE pin of 3.3V-5V chip	
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_3;	//ѡ��Ҫ�õ�GPIO����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	//��������Ϊ��ͨ���ģʽ				
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	//��������Ϊ�������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //��������Ϊ����		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//���������ٶ�Ϊ50MHZ
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);//���ÿ⺯������ʼ��GPIO
	
}

 /**
  * @file   LEDXToggle
  * @brief  LED����ת
  * @param  ledx:1--PC13;2--PB0;1--PB1
  * @retval ��
  */
void LEDXToggle(uint8_t ledx)
{
  if(ledx==1)
  {
    LED1_GPIO_PORT->ODR^=LED1_GPIO_PIN;
  }
  
}
