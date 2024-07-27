#include <stdio.h>

int main(void)
{
    double a, b;
    
    printf("2개의 실수를 입력하시오: ");
    scanf("%lf %lf", &a, &b);
    
    printf("합의 정수부 = %d\n", (int)a + (int)b);
    
    return 0;
}
