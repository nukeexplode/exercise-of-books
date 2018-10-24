#include <stdio.h>
int main()
{
	int a = 0xffffffff;
	printf("%d\n", !~a);
	int b = 0xffffffff;
	printf("%d\n", !a);
	int d = 0x000000ff;
	printf("%d\n", !(~d<<((sizeof(int)-1)<<3)));
	int c = 0x00ffffff;
	printf("%d\n", !(c>>((sizeof(int)-1)<<3)&0xff));
	return 0;
}
