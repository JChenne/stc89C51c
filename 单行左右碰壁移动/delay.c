#include"delay.h"
void DelayMs(unsigned int x)  
{
	unsigned char i;
	while(x--)
	{
		for (i = 0; i<13; i++)
		{}
	}
}
void delay1()               
{
	unsigned char i,j;
	for(i=0;i<250;i++)
	for(j=0;j<250;j++)
	;
}
void delay2()               
{
	unsigned char i,j;
	for(i=0;i<125;i++)
	for(j=0;j<250;j++)
	;
}
void delay(unsigned char c)
{
	unsigned char a,b;
	for(;c>0;c--)
		for(a=38;a>0;a--)
			for(b=138;b>0;b--);
}

