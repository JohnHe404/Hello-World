#include <reg52.h> //头文件
void lan(void);    
void  main ()
{ 
   while (1)    //无限循环
   {
     P1=0x7f;   //0111 1111  控制电流
	 lan();     //调用延迟函数
	 P1=0xbf;   //1011 1111
	 lan();
	 P1=0xdf;   //1101 1111
	 lan();
	 P1=0xef;   //1110 1111
	 lan();
	 P1=0xf7;   //1111 0111
	 lan();
	 P1=0xfb;   //1111 1011
	 lan();
	 P1=0xfd;   //1111 1101
	 lan();
	 P1=0xfe;   //1111 1110
	 lan();
   }
}

 void  lan(void)
 {
   int a = 0;
 	while (a <  10000) a++;
 }