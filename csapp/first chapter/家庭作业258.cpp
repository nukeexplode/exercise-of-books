#include <stdio.h>
int main()
{
	int a = 1;
	char *p = (char*)&a;
	printf("%d", p[0]); 
	
	
	return 0;
}
