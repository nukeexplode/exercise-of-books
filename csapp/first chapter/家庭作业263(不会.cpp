#include <stdio.h>
int srl(unsigned int x, int k);
int logical(unsigned int x, unsigned int y);
int main()
{
	printf("%u", srl(2147483648,1));
	//printf("%u", logical(2147483647,1073741824) );
	
	return 0;
}

int srl(unsigned int x, int k)
{
    int xsra = (int) x >> k;
    int w = sizeof(int)*8;
    unsigned int z = 2 << (w-k-1);
    
    return logical((z - 1),xsra);
}

int logical(unsigned int x, unsigned int y ) 
{
	printf("%d\n",y);
	printf("%d\n",x);
	return (~x & ~y) | (x & y);
}
