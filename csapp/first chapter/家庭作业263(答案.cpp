#include<stdio.h>
#include<climits>
int w = 8 * sizeof(int);
unsigned srl(unsigned x, int k) {
    /*Preform shift arithmetically*/
    unsigned xsra = (int)x >> k;

    int sign = (x & INT_MIN) && (k != 0);                  //符号为负且偏移不为0，则为 sign 为 1，否则为 0
    //xsra -= (unsigned int)(sign * (-1 << (w - k)));    //如果 (int)x 是负则从 xsrl 的前面将 k 个 1 换成 0
    /*题目要求不能用乘法，因此把上式换成*/
    xsra -= (unsigned int)(-sign & (-1 << (w - k)));
    return xsra;
}

int sra(int x, int k) {
    /*Perform shift logically*/
    int xsrl = (unsigned)x >> k;

    int sign = (k != 0) && (x & INT_MIN);  //符号为负且偏移不为0
    //xsrl += sign * (-1 << (w - k));     //如果是负则从 xsrl 的前面将 k 个 0 换成 1
    /*题目要求不能用乘法，因此把上式换成下式*/
    xsrl += (unsigned int)(-sign & (-1 << (w - k)));
    return xsrl;
}
int main() {
    //printf("%d\n%d\n%d\n%d\n%d\n", sra(123, 0) == 123 >> 0, sra(-100, 0) == -100 >> 0, sra(-2, w - 1) == -2 >> w - 1, srl(48, 0) == 48 >> 0, srl(UINT_MAX, 2) == UINT_MAX >> 2);
    //printf("\nsuccess\n");
    printf("%d", srl(2147483648,1));
    return 0;
}
