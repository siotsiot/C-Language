#include <stdio.h>

int main()
{
    int a = 10, b = 20;
    int* p1, * p2;

    p1 = &a;
    printf("1) p1 = &a;\n");
    printf(" a의 주소: %p\t a의 값: %d\n", &a, a);
    printf(" b의 주소: %p\t b의 값: %d\n", &b, b);
    printf("p1의 주소: %p\tp1의 값: %d\n", p1, *p1);
    //printf("p2의 주소: %p\tp2의 값: %d\n", p2, *p2);
    printf("\n");

    p2 = &b;
    printf("2) p2 = &b;\n");
    printf(" a의 주소: %p\t a의 값: %d\n", &a, a);
    printf(" b의 주소: %p\t b의 값: %d\n", &b, b);
    printf("p1의 주소: %p\tp1의 값: %d\n", p1, *p1);
    printf("p2의 주소: %p\tp2의 값: %d\n", p2, *p2);
    printf("\n");

    b = *p1;
    printf("3) b = *p1;\n");
    printf(" a의 주소: %p\t a의 값: %d\n", &a, a);
    printf(" b의 주소: %p\t b의 값: %d\n", &b, b);
    printf("p1의 주소: %p\tp1의 값: %d\n", p1, *p1);
    printf("p2의 주소: %p\tp2의 값: %d\n", p2, *p2);
    printf("\n");

    *p2 = 20;
    printf("4) *p2 = 20;\n");
    printf(" a의 주소: %p\t a의 값: %d\n", &a, a);
    printf(" b의 주소: %p\t b의 값: %d\n", &b, b);
    printf("p1의 주소: %p\tp1의 값: %d\n", p1, *p1);
    printf("p2의 주소: %p\tp2의 값: %d\n", p2, *p2);
    printf("\n");

    *p1 = *p2;
    printf("5) *p1 = *p2;\n");
    printf(" a의 주소: %p\t a의 값: %d\n", &a, a);
    printf(" b의 주소: %p\t b의 값: %d\n", &b, b);
    printf("p1의 주소: %p\tp1의 값: %d\n", p1, *p1);
    printf("p2의 주소: %p\tp2의 값: %d\n", p2, *p2);
    printf("\n");

    p2 = p1;
    printf("6) p2 = &b;\n");
    printf(" a의 주소: %p\t a의 값: %d\n", &a, a);
    printf(" b의 주소: %p\t b의 값: %d\n", &b, b);
    printf("p1의 주소: %p\tp1의 값: %d\n", p1, *p1);
    printf("p2의 주소: %p\tp2의 값: %d\n", p2, *p2);
    printf("\n");

    *p2 = 10;
    printf("7) *p2 = 10;\n");
    printf(" a의 주소: %p\t a의 값: %d\n", &a, a);
    printf(" b의 주소: %p\t b의 값: %d\n", &b, b);
    printf("p1의 주소: %p\tp1의 값: %d\n", p1, *p1);
    printf("p2의 주소: %p\tp2의 값: %d\n", p2, *p2);

    return 0;
}
