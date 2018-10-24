#include <stdio.h>
int main()
{
	unsigned int res,x,i,b;
	x=0x12345678;
	i=2;
	b=0xab;
	res = (x&~(0xff<<(i<<3)))|(b<<(i<<3));
	printf("%x",res);
	return 0;
}
