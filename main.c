#include <reg51.h>
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; //共阴,8为数码管0-9段码
unsigned char num=0;

sbit ex=P3^0;
void initex()  //定时器中断
{
	IT0=1; //边沿触发
	EX0=1; //打开外部中断0
	EA=1;  //开启总中断
	ex=1;
}
void display()
{
	P2=s[num];
	if(num==10)
		{
			num=0;
		}
}
void main()
{
	initex();
	while(1)
	{
		display();
	}
}

void ex_isr() interrupt 0  //外部中断的中断服务函数
{
	num++;
}