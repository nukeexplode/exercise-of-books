#include<stdio.h>
#include<climits>
int w = 8 * sizeof(int);
unsigned srl(unsigned x, int k) {
    /*Preform shift arithmetically*/
    unsigned xsra = (int)x >> k;

    int sign = (x & INT_MIN) && (k != 0);                  //����Ϊ����ƫ�Ʋ�Ϊ0����Ϊ sign Ϊ 1������Ϊ 0
    //xsra -= (unsigned int)(sign * (-1 << (w - k)));    //��� (int)x �Ǹ���� xsrl ��ǰ�潫 k �� 1 ���� 0
    /*��ĿҪ�����ó˷�����˰���ʽ����*/
    xsra -= (unsigned int)(-sign & (-1 << (w - k)));
    return xsra;
}

int sra(int x, int k) {
    /*Perform shift logically*/
    int xsrl = (unsigned)x >> k;

    int sign = (k != 0) && (x & INT_MIN);  //����Ϊ����ƫ�Ʋ�Ϊ0
    //xsrl += sign * (-1 << (w - k));     //����Ǹ���� xsrl ��ǰ�潫 k �� 0 ���� 1
    /*��ĿҪ�����ó˷�����˰���ʽ������ʽ*/
    xsrl += (unsigned int)(-sign & (-1 << (w - k)));
    return xsrl;
}
int main() {
    //printf("%d\n%d\n%d\n%d\n%d\n", sra(123, 0) == 123 >> 0, sra(-100, 0) == -100 >> 0, sra(-2, w - 1) == -2 >> w - 1, srl(48, 0) == 48 >> 0, srl(UINT_MAX, 2) == UINT_MAX >> 2);
    //printf("\nsuccess\n");
    printf("%d", srl(2147483648,1));
    return 0;
}
