#include <stdio.h>
int main()
{
	unsigned int x = 0x12345678;
	unsigned int n = 4;
	printf("%#x", x>>n | x<<(32-n));
	
	return 0;
}
