#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int 
uchar code vioce[]={0xd8,0xf7,	  //1
					0xbd,0xf8,	  //2
					0x87,0xf9,		//3
					0xe4,0xf9,		//4
					0x90,0xfa,		//5
					0x29,0xfb,		//6
					0xb1,0xfb,		//7
					0xef,0xfb};		//8 

sbit K1 = P1^0;
sbit K2 = P1^1;
sbit K3 = P1^2;
sbit K4 = P1^3;
sbit K5 = P1^4;
sbit K6 = P1^5;
sbit K7 = P1^6;
sbit K8 = P1^7;
uchar a,b;
sbit beep = P0^0;
void delay(int i);
void keyscan();
						


void main()
{				  
	TMOD = 0x01;
	TL0 = vioce[a];
	TH0 = vioce[b];													        
	ET0 = 1;
	TR0 = 0;
	EA = 1;
	while(1)
	{
		keyscan();
	}
}

void delay(int i)
{
	int j;
	for(i; i > 0; i --)
		for(j = 110; j > 0; j--);
}


void keyscan()
{
	if(K1 == 0)
	{
		delay(1);
		if(K1 == 0)
		{
			a = 0;
			b = 1;
			TR0 = 1;

		}
		while(K1 == 0);
		TR0 = 0;
	}
	if(K2 == 0)
	{
		delay(1);
		if(K2 == 0)
		{
			a = 2;
			b = 3;
			TR0 = 1;

		}
		while(K2 == 0);
		TR0 = 0;
	}
	if(K3 == 0)
	{
		delay(1);
		if(K3 == 0)
		{
			a = 4;
			b = 5;
			TR0 = 1;

		}
		while(K3 == 0);
		TR0 = 0;
	}
	if(K4 == 0)
	{
		delay(1);
		if(K4 == 0)
		{
			a = 6;
			b = 7;
			TR0 = 1;

		}
		while(K4 == 0);
		TR0 = 0;
	}
	if(K5 == 0)
	{
		delay(1);
		if(K5 == 0)
		{
			a = 8;
			b = 9;
			TR0 = 1;

		}
		while(K5 == 0);
		TR0 = 0;
	}
	if(K6 == 0)
	{
		delay(1);
		if(K6 == 0)
		{
			a = 10;
			b = 11;
			TR0 = 1;

		}
		while(K6 == 0);
		TR0 = 0;
	}
	if(K7 == 0)
	{
		delay(1);
		if(K7 == 0)
		{
			a = 12;
			b = 13;
			TR0 = 1;

		}
		while(K7 == 0);
		TR0 = 0;
	}
	if(K8 == 0)
	{
		delay(1);
		if(K8 == 0)
		{
			a = 14;
			b = 15;
			TR0 = 1;

		}
		while(K8 == 0);
		TR0 = 0;
	}
}

void timer()  interrupt 1
{
	TL0 = vioce[a];
 	TH0 = vioce[b];
	beep=~beep;
}