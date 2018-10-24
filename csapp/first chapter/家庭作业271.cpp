#include <stdio.h>
int main()
{
	unsigned int x = 0xffffffff;
	unsigned int bytenum = 0;
	int ret = x << (( 3 - bytenum ) << 3);
	printf("%d", ret>>24);
	
	return 0;
}
