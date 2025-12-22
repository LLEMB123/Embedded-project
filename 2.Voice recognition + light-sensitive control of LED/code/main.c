#include <REGX52.H>


//#include "LEDSS.H"
#include "XPT2046.H"
//#include "KEY.H"
#include "TIMER0.H"
#include "LCD1602.H"
//#include "DELAY.H"

sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;


unsigned char Counter,Compare;	//计数值和比较值，用于输出PWM
unsigned char a,b;
unsigned char c,d,e;
unsigned char Speed;
unsigned char tem;


void main()
{


		Timer0_Init();
//	 LCD_Init();
		P0=0XFF;
		P3=0XFF;
		P1=0XFF;
		P2=0XFF;
     a=0;
     b=0;
     c=0;
	tem=0;
	Speed=1;
    Compare=25;
	while(1)
	{
		
		
//			tem=XPT2046_ReadAD(0xEC);

	
	if(P3_0==0)
		
	{   a=1;	

	}		
	if(P3_0==1)
		
	{			
		   a=0;
	}	
	
	
	
	if(P3_1==0)
		
	{   b=1;	

	}		
	if(P3_1==1)
		
	{			
	  b=0;
	}	
	
	
	
	if(P3_2==0)
		
	{   c=1;	

	}		
	if(P3_2==1)
		
	{			
		   c=0;
	}	
	
	
	
	if(P3_3==0)
		
	{   d=1;	

	}		
	if(P3_3==1)
		
	{			
		   d=0;
	}	
	
	
	
	if(P3_4==0)
	{
		
		while(P3_4==0);
		if(P3_4==1);
		{
			
			Speed++;
			Speed%=5;
			if(Speed==0){Compare=0;}	//设置比较值，改变PWM占空比
			if(Speed==1){Compare=25;}
			if(Speed==2){Compare=50;}
			if(Speed==3){Compare=75;}
			if(Speed==4){Compare=100;}
		}

		}
	
		
	if(P3_5==0)
	{
		
		while(P3_5==0);
		if(P3_5==1);
		{
			
			
			Speed--;
			Speed%=5;
			if(Speed==0){Compare=0;}	//设置比较值，改变PWM占空比
			if(Speed==1){Compare=25;}
			if(Speed==2){Compare=50;}
			if(Speed==3){Compare=75;}
			if(Speed==4){Compare=100;}
			
		}

		}



		

	}
}

	
	
	




void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Counter++;
	Counter%=100;	//计数值变化范围限制在0~99

	if(Counter<Compare)	//计数值小于比较值
	{
		if(a==1)
		{
		led1=0;
		}			//输出1
		
		if(b==1)
		{
		led2=0;
		}			//输出1
		
		if(c==1)
		{
		led3=0;
		}			//输出1
		
		}			//输出1
	
		
		if(d==1)
		{
		  if(P1_3==1)
		
			  {  
				  if(a==1)
				  led1=0;
				  if(b==1)
				  led2=0;
				  if(c==1)
				  led3=0;
				  
//				led1=0;	
//				led2=0;	
//				led3=0;	
			  }		

		if(P1_3==0)
				
			{ 
				led1=1;	
				led2=1;	
				led3=1;	
			}		

		  }			//输出1
		
		  
		

	
	else		//计数值大于比较值
		
	{
		led1=1;		
		led2=1;
		led3=1;
	}
}

