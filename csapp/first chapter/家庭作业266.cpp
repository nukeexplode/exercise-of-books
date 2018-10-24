#include <stdio.h>
int main()
{
	unsigned int x = 0xf0000000;
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
//    printf("%x",x);
    printf("%x",x^(x>>1));
//    printf("%x",x & ~(x>>1));
	
	return 0;
}
