#include<reg51.h>
#include"lcd.h"
#include"delay.h"
#include"remote control.h"
void main()
{
 	unsigned char name[3]="pig";
	unsigned char name2[]="cat";
	int i,j,n;	
	LcdInit();
	LcdWriteCom(0x80+5);
	for(n=0;n<3;n++)
	{
		LcdWriteData(name2[n]);	
	}
	
	LcdWriteCom(0x06);						   //LcdWriteData	LcdWriteCom	
	for(j=0 ;j<14 ;j++ )					   //jΪ�ƶ�����+1
	{
		LcdWriteCom(0xc0);
		for(n=0;n<j;n++)
		{									  //����������
			LcdWriteData(' ');	
		}
		for(i=0;i<3;i++)
		LcdWriteData(name[i]);
		delay(50);
	}


	LcdWriteCom(0x04);					   //����һ
	for(j=0 ;j<13 ;j++ )				   //�ƶ�����
	{
		LcdWriteCom(0xc0+15);			   //��ʼλ��
		for(n=0;n<j;n++)
		{
			LcdWriteData(' ');	
		}
		for(i=2;i>=0;i--)				   //����������
		LcdWriteData(name[i]);
		delay(50);
	}
}