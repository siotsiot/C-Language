#include <stdio.h>

int main(void)
{
    char a;
    short b;
    int c;
    long d;
    long long e;
    float f;
    double g;
    long double h;
    
    printf("char형의 크기는 %d바이트입니다.\n", sizeof(a));
    printf("short형의 크기는 %d바이트입니다.\n", sizeof(b));
    printf("int형의 크기는 %d바이트입니다.\n", sizeof(c));
    printf("long형의 크기는 %d바이트입니다.\n", sizeof(d));
    printf("long long형의 크기는 %d바이트입니다.\n", sizeof(e));
    printf("float형의 크기는 %d바이트입니다.\n", sizeof(f));
    printf("double형의 크기는 %d바이트입니다.\n", sizeof(g));
    printf("long double형의 크기는 %d바이트입니다.\n", sizeof(h));
    
    return 0;
}
