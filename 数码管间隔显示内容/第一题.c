#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int

uchar code weixuan[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};	
uchar code duanxuan1[]={0x5b,0x3f,0x06,0x7d,0x3f,0x6d,0x06,0x3f};
uchar code duanxuan2[]={0x06,0x06,0x40,0x06,0x06,0x40,0x06,0x06};

void delay(int i)
{
int j;
for(i;i>0;i--)
for(j=110;j>0;j--);
}

void main()
{
	int a,b;
	for(a=0;a<300;a++)
	for(b=0;b<8;b++)
	{
		P1=weixuan[b];
		P0=duanxuan1[b];
		delay(1);
		P0=0x00;
	}
	delay(100);
	for(a=0;a<300;a++)
	for(b=0;b<8;b++)
	{
		P1=weixuan[b];
		P0=duanxuan2[b];
		delay(1);
		P0=0x00;
	}
	delay(100);
}
