//独立键盘控制
#include <reg52.h>

#define uint unsigned int//定义uint类型
#define uchar unsigned char//定义uchar类型

uint num = 1;//led显示的数字
uchar flag = 0;//led显示位

uchar a[8] ={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};    //P2 1-8 位
uchar b[10] ={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};  //P1 0-9 段


sbit key1 = P0^0;//连接键盘的I/O口
sbit key2 = P0^1;
sbit key3 = P0^2;
sbit key4 = P0^3;

void keyscan(void);//扫描函数
void delays(void);//延迟函数
void main()
{
	while(1)
	{
		keyscan();  
		
		if(num > 9)
			num = 0;
		
		if(flag == 1)//关闭led输出
		{
		    P2 = 0xff;	
			
		}
	  else
		{
			P2 = a[0];
			P1 = b[num];
		}
				
	}
}
void keyscan(void)//扫描函数
{
	if(key1 == 0)
	{
		delays();
		if(key1 == 0)
			flag = 1;
		while(!key1);
	}

	if(key2 == 0)
	{
		delays();
		if(key2 == 0)
		 flag = 0;
		while(!key2);
	}

	if(key3 == 0)
	{
		delays();
		if(key3 == 0)
			num++;
		while(!key3);
	}

	if(key4 == 0)
	{
		delays();
		if(key4 == 0)
			num--;
		while(!key4);
	}
}
void delays(void)//延迟函数
{
	int i;
	int j;
	for(i = 0;i<10;i++)
		for(j = 0; j<124;j++);
}	
