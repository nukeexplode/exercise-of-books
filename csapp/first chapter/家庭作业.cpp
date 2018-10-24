#include <stdio.h>
int srl(unsigned int x, int k);
int main()
{
	srl(1,2);
	
	return 0;
}

int srl(unsigned int x, int k)
{
    int xsra = (int) x >> k;
    int w = sizeof(int)*8;
    unsigned z = 2 << (w-k-1);
    
    return (z - 1) & xsra;
}
