#include <stdio.h>

int main(void)
{
    int num1, num2;
    
    printf("정수를 입력하시오: ");
    scanf("%d", &num1);
    printf("정수를 입력하시오: ");
    scanf("%d", &num2);
    
    printf("두 수의 합은 %d입니다.\n", num1 + num2);
    printf("두 수의 차는 %d입니다.\n", num1 - num2);
    
    return 0;
}
