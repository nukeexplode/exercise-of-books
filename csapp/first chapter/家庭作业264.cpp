#include <stdio.h>
int main()
{
	unsigned int y = 1;
	//scanf("%u", &y);
	unsigned int x = 0x55a55555;
	printf("%d", y&x!=0);
	
	return 0;
}
