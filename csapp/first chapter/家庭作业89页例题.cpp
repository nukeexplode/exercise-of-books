#include <stdio.h>
int main()
{
	int s = (sizeof(int)-1)<<3;
	int x = 0x12345678;
	int res = x>>s;
	printf("%x", res);
	
	return 0;
}
