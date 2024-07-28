#include <stdio.h>

int main(void)
{
    int num;
    
    printf("숫자를 입력하시오: ");
    scanf("%d", &num);
    printf("LSB는 %d\n", num & 1); // 1을 2진수로 표현하면 LSB가 1이고 나머지 비트는 전부 0이므로 &(AND)연산자를 이용해서 LSB 판별 가능.
    
    return 0;
}
