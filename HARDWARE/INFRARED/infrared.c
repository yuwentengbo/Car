#include "infrared.h"

void Infrared_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_6| GPIO_Pin_7);
}


u8 Infrared_scan()
{
	if(1 == DOL || 1 == DOR)
	{
		if(1 == DOL && 0 == DOR)		return ONLY_L;
		else if(0 == DOL && 1 == DOR)	return ONLY_R;
		else if(1 == DOL && 1 == DOR)	return BOTH;
	}
	return 0;
}

