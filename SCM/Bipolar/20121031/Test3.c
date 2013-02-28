//今天老师发的程序优化之后的版本                                              2012/10/31   by 赫

#include<reg52.h>

 void delays(int a);

    void main()
  {
	while(1)
	{
		P1 = 0xfe;
		delays(1000);
		P1 = 0xff;
		delays(1000);
	}
 }  


   void delays(int a)	//延迟函数
 {
	int i;

	for(i = 0;i < a*124;i++) ;
 }