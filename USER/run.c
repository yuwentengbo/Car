#include "run.h"
#include "infrared.h"
#include "bujin.h"
#include "delay.h"
#include "mpu6050.h"

u8 speed = 6;

void control()
{
	u8 turn = 0;
	while(1)
	{
		turn = Infrared_scan();
		switch(turn)
		{
			case 0:			Moter_Go(speed,0); 	 	break;	//直走
			case ONLY_L:	Moter_Left(speed+3,0);  break;	//左转
			case ONLY_R:	Moter_Right(speed+3,0); break;	//右转
			case BOTH:		Moter_Stop();	 		return;	 
		}
	}
}

void xunji()
{
	while(1)
	{
		control();
	}
}



void qiaoqiao()
{
	u8 i,flag;
	float angle_x;
	
	control();
	for(i=0;i<50;i++)
	{
		Moter_Go(speed+1,0); 
	}
	while(1)
	{
		angle_x = mpu6050_get();
	
		if(angle_x< 0||angle_x>173.5)
		{
			flag = 1;
		}
		else if(angle_x<168.5)
		{
			flag = 0;
		}
		else
		{
			break;
		}
		for(i=0;i<30;i++)
		{
			Moter_Go(speed+1,flag); 
		}
	}
	
	delay_ms(5000);
	
	speed = 4;
	control(); 
}



