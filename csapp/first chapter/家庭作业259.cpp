#include <stdio.h>
int main()
{
//	int x = 0x89abcdef;
//	int y = 0x76543210;
//	printf("%x",y/16/16+......); 
	int x = 0x89abcdef;
	int y = 0x76543210;
	printf("%#x", (x&0xff)|(y&~0xff));
	
	return 0;
}
