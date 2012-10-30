#include <reg52.h>
void lan(void);
void  main ()
{ 
   while (1)
   {
     P1=0x7f;
	 lan();
	 P1=0xbf;
	 lan();
	 P1=0xdf;
	 lan();
	 P1=0xef;
	 lan();
	 P1=0xf7;
	 lan();
	 P1=0xfb;
	 lan();
	 P1=0xfd;
	 lan();
	 P1=0xfe;
	 lan();
   }
}

 void  lan(void)
 {
   int a = 0;
 	while (a <  10000) a++;
 }