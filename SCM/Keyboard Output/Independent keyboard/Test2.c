//独立键盘控制led数字板显示与多位双极亮灯

#include <reg52.h>//调用头文件reg52.h

#define uchar unsigned char //定义uchar类型


int flag = 0;//位
int num = 0;//数字
uchar a[8] ={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};    //P2 1-8 位
uchar b[10] ={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};  //P1 0-9 段
uchar c[8] ={0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00}; //双极管
sbit key1 = P0^0;//键盘输出
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
		
		if(flag > 7) flag = 0;//flag 0-7之间控制
		if(flag < 0) flag = 7;//同上
    if(num > 9) num = 0;//num 0-9之间控制
		if(num < 0) num = 9;//同上
		P3 = P2 = a[flag];//传递给P3,P2 I/O口输出
		P1 = b[num]; //同上传递给P1
				
	}
}
void keyscan(void) //臃肿的扫描函数
{
	if(key1 == 0)
	{
		delays();
		if(key1 == 0)
			flag++;
		while(!key1);//限制避免按键多次输入
	}

	if(key2 == 0)
	{
		delays();
		if(key2 == 0)
		 flag--;
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
void delays(void)//延迟
{
	int i;
	int j;
	for(i = 0;i<10;i++)
		for(j = 0; j<124;j++);
}	
