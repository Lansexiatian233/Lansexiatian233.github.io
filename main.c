#include <reg51.h>
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; //����,8Ϊ�����0-9����
unsigned char num=0;

sbit ex=P3^0;
void initex()  //��ʱ���ж�
{
	IT0=1; //���ش���
	EX0=1; //���ⲿ�ж�0
	EA=1;  //�������ж�
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

void ex_isr() interrupt 0  //�ⲿ�жϵ��жϷ�����
{
	num++;
}