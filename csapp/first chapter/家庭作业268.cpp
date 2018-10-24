#include <stdio.h>
int main()
{
	//我认为是把x的最低n位改为1 
	unsigned int x = 1;
	unsigned int n = 6;
	printf("%#x", ((x+1)<<n)-1);
	
	return 0;
}
