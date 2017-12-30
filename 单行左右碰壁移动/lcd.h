#ifndef __LCD_H_
#define __LCD_H_
#include<reg51.h>
void LcdWriteCom(unsigned char com);
void LcdWriteData(unsigned char dat);
void LcdInit();
sbit e=P2^7;
sbit rw=P2^5;
sbit rs=P2^6;
#endif