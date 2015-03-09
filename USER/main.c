#include "delay.h"
#include "usart.h"
#include "bujin.h"
#include "key.h"
#include "infrared.h"
#include "string.h"
#include "run.h"

/*
����С����ѭ�������ΰ�ƽ��

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
	 case KEY0_PRES: 	xunji();	 break;		//��KEY0ʱѰ��
	 case KEY1_PRES:  	qiaoqiao();  break;	    //��KEY1ʱ�����ΰ�
	 default: break;
	}
			
	return 0;
}


