#include <stdio.h>
double get_bigger(double a, double b);

int main(void)
{
    double a, b;
    
    printf("실수를 입력하시오: ");
    scanf("%lf", &a);
    printf("실수를 입력하시오: ");
    scanf("%lf", &b);
    printf("더 큰 수는 %lf입니다.\n", get_bigger(a, b));

    return 0;
}

double get_bigger(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}
