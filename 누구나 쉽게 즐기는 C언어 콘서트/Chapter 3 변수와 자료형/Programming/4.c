#include <stdio.h>

int main(void)
{
    double x, result;
    
    printf("x의 값을 입력하시오: ");
    scanf("%lf", &x);
    
    result = 3 * x * x * x - 7 * x * x + 9;
    
    printf("다항식의 값은 %lf입니다.\n", result);
    
    return 0;
}
