//对源文件Test3.c的优化                                                                               
#include<reg52.h>


 void delays (void);

    void main()
  {
	while(1)
	{
		P1 = 0xfe;
		delays(); //去除不必要的传递给函数的值
		P1 = 0xff;
		delays();
	}
 }  


   void delays(void)	//延迟函数
 {
	int i = 0;

	 while (i < 124000) i++;  //直接进行124000次循环
 }
