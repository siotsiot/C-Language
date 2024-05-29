#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum_rec(int);

int main(void)
{
    int n;

    printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);

    printf("입력된 숫자에 포함된 모든 숫자의 합: %d\n", sum_rec(n));

    return 0;
}

int sum_rec(int n)
{
    int sum = 0;

    if (n < 10)
        return n;

    sum = n % 10;

    return sum + sum_rec(n / 10);
}
