#include<reg51.h>
#include<intrins.h>
int num,aa;

void Delay10ms(unsigned int c)   //��� 0us
{
    unsigned char a, b;

	//--c�Ѿ��ڴ��ݹ�����ʱ���Ѿ���ֵ�ˣ�������for����һ��Ͳ��ø�ֵ��--//
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
	TMOD=0X01;							//��ʱ����ʼ��
	TH0=(65536-5000)/256;
	TL0=(65536-5000)%256;
	TR0=1;

//   IT1=0;       //�͵�ƽ����
//   IT1=1;       //�½��ش���	
	EA=1;
	ET0=1; 
	EX1=1;
	aa=0x01;
	 while(1)
	 {
	 	if(num>=30)
		{	
			num=0;					//��ȫ��
			P1=aa;
			Delay10ms(10);
			aa=_crol_(aa,1);	 	//���ƣ���ˮ��
		}			
	}
}
void t0() interrupt 1							 //��ʱ��
{
	TH0=(65536-5000)/256;
	TL0=(65536-5000)%256;
	num++;
}

void I1() interrupt 2
{
	TR0=~TR0;
}