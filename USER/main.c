#include "delay.h"
#include "usart.h"
#include "bujin.h"
#include "key.h"
#include "infrared.h"
#include "string.h"
#include "run.h"

/*
智能小车，循迹，跷跷板平衡

*/

void System_init()
{
	delay_init();
	NVIC_Configuration();
	uart_init(9600);
	UART2_Init(115200);
	KEY_Init();
	bujin_init();
	Infrared_init();
}

int main(void) 
{
	
	u8 is_stop = 0;
	
	while(is_stop == 0)
	{
		is_stop = KEY_Scan(0);
		delay_ms(10);
	}
	switch(is_stop)
	{
	 case KEY0_PRES: 	xunji();	 break;		//按KEY0时寻迹
	 case KEY1_PRES:  	qiaoqiao();  break;	    //按KEY1时上跷跷板
	 default: break;
	}
			
	return 0;
}


