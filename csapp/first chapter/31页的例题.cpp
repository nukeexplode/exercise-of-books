#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,size_t len ); 
void show_pointer(void *x);
void show_int(int x); 
void show_float(float x);
void test_show_bytes(int val);
void show_long(long x);
int main()
{
	test_show_bytes(123456.24); 
	
	return 0;
}

void test_show_bytes(int val) {
	int ival = val;
	float fval = (float)ival;
	int *pval = &ival;
	long lval = (long)val; 
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
	show_long(lval); 
//	printf("\n");
//	printf("%d\n",(byte_pointer) &pval);//是把&pval变成char的指针 
//	printf("%d", &pval);
}
void show_bytes(byte_pointer start,size_t len ) {
	size_t i;
	for ( i=0; i<len; i++ ) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_long(long x) {
	show_bytes((byte_pointer) &x, sizeof(long));
}
