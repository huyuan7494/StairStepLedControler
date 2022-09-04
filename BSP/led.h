#ifndef __LED_H
#define __LED_H

#include "stm32f0xx.h"

#define LED1_GPIO_RCC           RCC_AHBPeriph_GPIOB
#define LED1_GPIO_PORT          GPIOB
#define LED1_GPIO_PIN      		GPIO_Pin_4
#define LED1_ONOFF(x)     		GPIO_WriteBit(GPIOB,GPIO_Pin_4,x);
#define SET_OE_PIN(x)           GPIO_WriteBit(GPIOB,GPIO_Pin_3,x);

void LED_GPIO_Config(void);	

#endif
