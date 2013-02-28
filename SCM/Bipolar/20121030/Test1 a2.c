//P1 I/O口 控制循环亮灯单片机程序 2012/10/30                                       by 赫
//修改2012/11/5     减少延迟函数计算，否则灯亮速度过慢，灯亮速度3次递增          by赫 


#include <reg52.h> //头文件
void sleep(int a);    
void  main ()
{ 
	int a,b;
	 
	while (1)
  {
		b = 0;
		while((a = b++*5000) < 20000)    //无限循环
   {
    P1=0x7f;   //0111 1111  控制电流
	  sleep(a);     //调用延迟函数
	  P1=0xbf;   //1011 1111
	  sleep(a);
	  P1=0xdf;   //1101 1111
	  sleep(a);
	  P1=0xef;   //1110 1111
	  sleep(a);
	  P1=0xf7;   //1111 0111
	  sleep(a);
	  P1=0xfb;   //1111 1011
	  sleep(a);
	  P1=0xfd;   //1111 1101
	  sleep(a);
	  P1=0xfe;   //1111 1110
	  sleep(a);
   }
 }
}

 void  sleep(int a)
 {
   int i = 0;
 	//while (i++ <  10000) ; 优化前
    while (i < a) i++; //优化后
 }
