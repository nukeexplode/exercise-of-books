#include <stdio.h>
int main()
{
	unsigned int x = 0xffffffff;
	x ^= (x>>16);
	x ^= (x>>8);
	x ^= (x>>4);
	x ^= (x>>2);
	x ^= (x>>1);//这个x的值的二进制是 11001100110011001100110011001100
	printf("%u", x&0x1); 
	
	return 0;
}
