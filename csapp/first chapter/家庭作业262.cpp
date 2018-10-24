#include <stdio.h>
#include <limits.h>
int int_shifts_are_arithmetic() ;
int main()
{
	int x = INT_MIN;
	int y = x>>31;
	

	
	if((y>>1 & 0xffffffff) == 0){
		printf("算术右移 %d", int_shifts_are_arithmetic() ); 
	}else{
		printf("逻辑右移"); 
	}
	
	return 0;
}

	int int_shifts_are_arithmetic() 
	{
    	return -2 >> 1 == -1;
	}//还可以这样写(这是别人的) 
