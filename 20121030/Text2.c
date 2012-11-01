//P1 I/O口 控制循环亮灯单片机程序  第二种使用数组的实现 2012/11/1                                       by 赫

#include <reg52.h> //头文件
void sleep(void);    
void  main ()
{ 
   int a;
   int led[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
   while (1)    //无限循环
   {
     for (a = 0;a < 8;a++)
	 {
	    P1 = led[a];
		sleep();
	 }
   }
}

 void  sleep(void)
 {
   int i = 0;
 	while (i++ <  10000) ;
 }