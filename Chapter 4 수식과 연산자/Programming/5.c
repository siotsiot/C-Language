#include <stdio.h>

int main(void)
{
    int a, b;
    
    printf("첫 번째 정수를 입력하시오: ");
    scanf("%d", &a);
    printf("두 번째 정수를 입력하시오: ");
    scanf("%d", &b);
    
    printf("몫은 %d이고, 나머지는 %d입니다.\n", a / b, a % b);
    
    return 0;
}
