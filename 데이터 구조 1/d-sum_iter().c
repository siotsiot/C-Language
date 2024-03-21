#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum_iter(int);

int main(void)
{
    int n, result;

    printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);

    result = sum_iter(n);

    printf("입력된 숫자에 포함된 모든 숫자의 합: %d\n", result);

    return 0;
}

int sum_iter(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
