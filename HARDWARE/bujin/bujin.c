#include "bujin.h"
#include "delay.h"

void bujin_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
}

void Moter_Stop()
{
	//right
	PCout(6) = 0; PCout(7) = 0; PCout(8) = 0; PCout(9) = 0;
	//left
	PAout(4) = 0; PAout(5) = 0; PAout(6) = 0; PAout(7) = 0; 
}

void Moter_Go(u8 speed,u8 flag)
{
	if(flag == 0)
	{
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 0; PAout(7) = 1;
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		delay_ms(speed);
		
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 0; PAout(7) = 1;
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1;  PCout(9)= 0;
		delay_ms(speed);
		
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 1; PAout(7) = 0;
		PCout(6) = 0; PCout(7) = 1;  PCout(8) = 0; PCout(9) = 1;
		delay_ms(speed);
		
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 1; PAout(7) = 0;
		PCout(6) = 1; PCout(7) = 0;  PCout(8)= 0;  PCout(9) = 1;
		delay_ms(speed);
	}
	else
	{
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 1; PAout(7) = 0;
		PCout(6) = 1; PCout(7) = 0;  PCout(8)= 0;  PCout(9) = 1;
		delay_ms(speed);
		
		
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 1; PAout(7) = 0;
		PCout(6) = 0; PCout(7) = 1;  PCout(8) = 0; PCout(9) = 1;
		delay_ms(speed);
		
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 0; PAout(7) = 1;
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1;  PCout(9)= 0;
		delay_ms(speed);
		
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 0; PAout(7) = 1;
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		delay_ms(speed);
	}
}

void Moter_Left(u8 speed,u8 flag)
{
	if(0  == flag)
	{
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 1; PAout(7) = 0;
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		delay_ms(speed);
		
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 1; PAout(7) = 0;
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1;  PCout(9)= 0;
		delay_ms(speed);
		
		PAout(4) = 0; PAout(5) = 1;  PAout(6) = 0; PAout(7) = 1;
		PCout(6) = 0; PCout(7) = 1;  PCout(8) = 0; PCout(9) = 1;
		delay_ms(speed);
		
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 0; PAout(7) = 1;
		PCout(6) = 1; PCout(7) = 0;  PCout(8)= 0;  PCout(9) = 1;
		delay_ms(speed);
	}
	else
	{
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 0; PAout(7) = 1;
		PCout(6) = 1; PCout(7) = 0;  PCout(8)= 0;  PCout(9) = 1;
		delay_ms(speed);
		
		PAout(4) = 0; PAout(5) = 1;  PAout(6) = 0; PAout(7) = 1;
		PCout(6) = 0; PCout(7) = 1;  PCout(8) = 0; PCout(9) = 1;
		delay_ms(speed);
		
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 1; PAout(7) = 0;
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1;  PCout(9)= 0;
		delay_ms(speed);
		
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 1; PAout(7) = 0;
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		delay_ms(speed);
	}

}

void Moter_Right(u8 speed,u8 flag)
{
	if(0 == flag)
	{
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 0; PCout(9) = 1;
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 0; PAout(7) = 1;
		delay_ms(speed);
		
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 0; PCout(9) = 1;
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 0; PAout(7) = 1;
		delay_ms(speed);
		
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1; PCout(9) = 0;
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 1; PAout(7) = 0;
		delay_ms(speed);
		
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 1; PAout(7) = 0;
		delay_ms(speed);
	}
	else
	{
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 1; PCout(9) = 0;
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 1; PAout(7) = 0;
		delay_ms(speed);
		
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 1; PCout(9) = 0;
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 1; PAout(7) = 0;
		delay_ms(speed);
		
		PCout(6) = 0; PCout(7) = 1; PCout(8) = 0; PCout(9) = 1;
		PAout(4) = 0; PAout(5) = 1; PAout(6) = 0; PAout(7) = 1;
		delay_ms(speed);
		
		PCout(6) = 1; PCout(7) = 0; PCout(8) = 0; PCout(9) = 1;
		PAout(4) = 1; PAout(5) = 0; PAout(6) = 0; PAout(7) = 1;
		delay_ms(speed);
		
	}
}

