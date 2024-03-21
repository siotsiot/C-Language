#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int n;
    int sum = 0;

    printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    printf("입력된 숫자에 포함된 모든 숫자의 합: %d\n", sum);

    return 0;
}
