#include"lcd.h"
#include"delay.h"
#include<reg51.h>
void LcdWriteCom(unsigned char com)
{
	e=0;
	rs=0;
	rw=0;
	P0=com;
	DelayMs(10);
	e=1;
	DelayMs(10);
	e=0;	
}

void LcdWriteData(unsigned char dat)
{
	e=0;
	rs=1  ;
	rw=0;
	P0=dat;
	DelayMs(10);
	e=1;
	DelayMs(10);
	e=0;								
}

void LcdInit()
{
	DelayMs(300);
	LcdWriteCom(0x38);
	LcdWriteCom(0x08);
	LcdWriteCom(0x01);
	LcdWriteCom(0x06);
	LcdWriteCom(0x0c);	
}
