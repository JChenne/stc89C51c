#include<reg51.h>

sbit key1= P2^7;
sbit key2= P2^6;
int i,b,d,max,j;
unsigned int sum1,sum2;
unsigned char code weixuan[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
unsigned char led[11] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0X40};
unsigned char a[8],table[8];

void delay(unsigned int i)
{
	unsigned int j,k;	
	for(j = 0; j < i; j++)	
	for(k = 0; k < 120; k++);
}
void main()
{  	 		
	TMOD = 0X01;	
	TH0 = 0X02;	
	TL0 = 0X01;	
	EA = 1;	
	ET0 = 1;	
	TR0 = 1; 
	while(1)
	{		
	loop:	
		sum1=TH0;
		sum2=TL0;
		
		a[0]=led[sum1 % 10];
		a[1]=led[sum1 / 10 % 10];
		a[2]=led[sum2 % 10];
		a[3]=led[sum2 / 10 % 10];
		a[4]=led[sum1 %  5   ];
		a[5]=led[sum1 / 5 % 5];
		a[6]=led[sum2  % 5];
		a[7]=led[sum2 / 5 % 5];
		for(b=0;b<10;b++)
		{
			for(d=0;d<8;d++)
			{
				P1=weixuan[d];
				P0=a[d];
				delay(1);
				P0=0x00;	
			}		
		 	if (key1 != 0xFF)		//检测按键K1是否按下
			{
				delay(2);	//消除抖动
				if (key1 != 0xFF)	//再次检测按键是否按下
				{
					delay(2);
					while  (key1 != 0xFF)	 //检测按键是否松开
					{
						delay(2);
					
					}
					while(1)
					{
						for(d=0;d<8;d++)
						{	P1=weixuan[d];
							P0=a[d];
							delay(1);
							P0=0x00;
						}  
					    if (key1 != 0xFF)		//检测按键K1是否按下
						{
							delay(2);	//消除抖动
							if (key1 != 0xFF)	//再次检测按键是否按下
							{	 
								delay(2);
								while (key1 != 0xFF)	 //检测按键是否松开
								{
									delay(2);
									
								} 
								goto loop;
							}	
					    }
	
						if (key2 != 0xFF)		//检测按键K1是否按下
						{
							delay(2);	//消除抖动
							if (key2 != 0xFF)	//再次检测按键是否按下
							{	 
								delay(2);
								table[0]=sum1 % 10;
								table[1]=sum1 / 10 % 10;
								table[2]=sum2 % 10;
								table[3]=sum2 / 10 % 10;
								table[4]=sum1 %  5   ;
								table[5]=sum1 / 5 % 5;
								table[6]=sum2  % 5;
								table[7]=sum2 / 5 % 5;
								max=table[0];
								for(i=0;i<7;i++)
								 {
								 	  for(j=0;j<7-i;j++)
									 {
										 if(table[j]>table[j+1])
										 {
										 	max=table[j];
											table[j]=table[j+1];
											table[j+1]=max;
										 }
									 }
								 }
								while(1)
								{	
									for(b=0;b<8;b++)
									{
										P1=weixuan[b];
										P0=led[table[b]];
										delay(1);
										P0=0x00;
									}
									if (key1 != 0xFF)		//检测按键K1是否按下
									{
										delay(2);	//消除抖动
										if (key1 != 0xFF)	//再次检测按键是否按下
										{	 
											delay(2);
											while (key1 != 0xFF)	 //检测按键是否松开
											{
												delay(2);
												
											} 
											goto loop;
										}	
								    }	
								}
							}	
					    }
					}
					
				}
			}

		}
	}
}






void init() interrupt 1

{

	TH0 = 0X02;
	
	TL0 = 0X01;

}