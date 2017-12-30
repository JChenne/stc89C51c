#include <reg51.h>
#define uchar  unsigned char
#define uint   unsigned int
sbit key1=P2^7;
sbit key2=P2^6;
uchar code weixuan[8] = {0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uchar code duanxuan[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
                          0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
unsigned char a[6];
int num = 0;

void Timer0_start();				//������ʱ��0
void Delay10ms(unsigned char c);  	//��ʱ10ms

void delay(int i)
{
	int j;
	for(i;i>0;i--)
	for(j=110;j>0;j--);
}

void main()
{
	int b,i;
loop:	
	Timer0_start();
	EA=0;
	while(1)
	{
		num=0;
		if (key1 != 0xFF)		//��ⰴ��K1�Ƿ���
		{
			Delay10ms(1);	//��������
			if (key1 != 0xFF)	//�ٴμ�ⰴ���Ƿ���
			{
				EA=1 ;
				i = 0;
				while ((i<50) && (key1 != 0xFF))	 //��ⰴ���Ƿ��ɿ�
				{
					Delay10ms(1);
					i++;
				}
				while(1)
				{
				   	 a[0] = duanxuan[num / 100000];
					 a[1] = duanxuan[num % 100000 / 10000];
					 a[2] = duanxuan[num % 10000 / 1000]   | 0x80;
					 a[3] = duanxuan[num % 1000 / 100];
					 a[4] = duanxuan[num % 100 / 10];
					 a[5] = duanxuan[num % 10];
					 for(b=0;b<6;b++)
					 {
					 	P1=weixuan[b];
						P0=a[b];
						delay(1);
						P0=0x00;
					 }
					if (key1 != 0xFF)		//��ⰴ��K1�Ƿ���
					{	
						EA=0;
						Delay10ms(1);	//��������
						if (key1 != 0xFF)	//�ٴμ�ⰴ���Ƿ���
						{							
							i = 0;
							while ((i<50) && (key1 != 0xFF))	 //��ⰴ���Ƿ��ɿ�
							{
								Delay10ms(1);
								i++;
							}
							 while(1)
							 {
							 	if (key2 != 0xFF)		//��ⰴ��K1�Ƿ���
								{
									Delay10ms(1);	//��������
									if (key2 != 0xFF)	//�ٴμ�ⰴ���Ƿ���
									{
										goto loop;
										i = 0;
										while ((i<50) && (key2 != 0xFF))	 //��ⰴ���Ƿ��ɿ�
										{
											Delay10ms(1);
											i++;
										}
									}
								}
								 for(b=0;b<6;b++)
								 {
								 	P1=weixuan[b];
									P0=a[b];
									delay(1);
									P0=0x00;
								 }
							}
						}
					}	
				}
			}
	   }
	}
}

void Timer0_start()
{
	TMOD = 0X01;	//ѡ�ü���ģʽ�� ѡ��ģʽ1
	TH0 = (65536 - 1000) / 256;   //��������װ��ֵ	1ms
	TL0 = (65536 - 1000) % 256;
	EA = 1;	     //���������ж�
	ET0 = 1;       //������ʱ��T0�ж�
	TR0 = 1;	     //����T0��ʱ��
}
void Delay10ms(unsigned char c)
{
	unsigned char a,b;
	for(; c > 0; c --)
		for(a = 38; a > 0; a --)
			for( b = 138; b >0 ; b--);
}
void timer0() interrupt 1
{
	TH0 = (65536 - 1000) / 256;   //��������װ��ֵ
	TL0 = (65536 - 1000) % 256;
	num ++;
}
