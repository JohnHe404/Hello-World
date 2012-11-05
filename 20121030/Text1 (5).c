//P1 I/O口 控制循环亮灯单片机程序 2012/10/30                                       by 赫
//2012/11/05      使用递归往复循环     by赫

#include <reg52.h> //头文件
void sleep(void);    
void led(int * a,int b);
void  main ()
{ 
   int a[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
   led(a,0);
}

 void  sleep(void)
 {
   int i = 0;
 	//while (i++ <  10000) ; 优化前
    while (i < 20000) i++; //优化后
 }
 
 void led(int * a,int b)
 { 
	 P1 = a[b++];
	 sleep();
	 if (b < 8) led(a,b);
	 P1 = a[--b];
	 sleep();
}