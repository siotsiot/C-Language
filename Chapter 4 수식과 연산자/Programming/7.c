#include <stdio.h>

int main(void)
{
    double x;
    
    printf("x의 값을 입력하시오: ");
    scanf("%lf", &x);
    
    printf("수식의 값은 %lf입니다.\n", (x * x * x - 20) / (x - 7));
    
    return 0;
}
