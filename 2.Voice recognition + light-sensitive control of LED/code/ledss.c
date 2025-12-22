#include "DELAY.H"
#include "LEDSS.H"
#include <REGX52.H>

sbit led0=P0^0;
sbit led1=P0^1;
sbit led2=P0^2;
void led0ss(int s)
{
	led0=0;
	Delay(s);
	led0=1;
	Delay(10000-s);
	
}
void led1ss(int s)
{
	led1=0;
	Delay(s);
	led1=1;
	Delay(255-s);
	
}
void led2ss(int s)
{
	led2=0;
	Delay(s);
	led2=1;
	Delay(255-s);
	
}