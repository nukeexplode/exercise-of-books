#include <stdio.h>
int main()
{
	//����Ϊ�ǰ�x�����nλ��Ϊ1 
	unsigned int x = 1;
	unsigned int n = 6;
	printf("%#x", ((x+1)<<n)-1);
	
	return 0;
}
