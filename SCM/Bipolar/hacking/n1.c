//控制发光的双击管从2个方向移动
#include <reg52.h>
void sleep(void);
void main()
{
	int number,m,n;
	int i;

	while(1){
		i = 0;
		m = 0x80;
		n = 0x01;
		while(i < 8){
			number = m | n;//m或n
			P1 = number;
			sleep();
			m >>= 1;//移位
			n <<= 1;
			i++;
		}
	}
}

void sleep(void)//延迟函数
{
	int i = 0;

	while(i < 15000) i++;
}
