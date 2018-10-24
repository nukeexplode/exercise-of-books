#include <stdio.h>
#include <limits.h>
int main()
{
	int x = INT_MAX;
	float f= 3.4E38;
	double d=1e40;
	printf("%d %d %d %d %d %d %d %d\n",x==(int)(double)x,x==(int)(double)x,d==(double)(float)d,f==(float)(double)f,f==-(-f),1.0/2.0==1/2.0,d*d>=0.0,(f+d)-f==d);
	printf("%f\n",(double)(float)d);
	printf("%f\n",(float)(double)f);
	printf("%f\n",f==-(-f));
	
	return 0;
}
