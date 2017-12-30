#include<reg51.h>
#include<intrins.h>
int num,aa;

void Delay10ms(unsigned int c)   //误差 0us
{
    unsigned char a, b;

	//--c已经在传递过来的时候已经赋值了，所以在for语句第一句就不用赋值了--//
    for (;c>0;c--)
	{
		for (b=38;b>0;b--)
		{
			for (a=130;a>0;a--);
		}         
	}
}
void main()
{
	TMOD=0X01;							//定时器初始化
	TH0=(65536-5000)/256;
	TL0=(65536-5000)%256;
	TR0=1;

//   IT1=0;       //低电平触发
//   IT1=1;       //下降沿触发	
	EA=1;
	ET0=1; 
	EX1=1;
	aa=0x01;
	 while(1)
	 {
	 	if(num>=30)
		{	
			num=0;					//灯全灭
			P1=aa;
			Delay10ms(10);
			aa=_crol_(aa,1);	 	//右移，流水灯
		}			
	}
}
void t0() interrupt 1							 //定时器
{
	TH0=(65536-5000)/256;
	TL0=(65536-5000)%256;
	num++;
}

void I1() interrupt 2
{
	TR0=~TR0;
}