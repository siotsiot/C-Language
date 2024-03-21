#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int addEven(int);

int main(void)
{
	int n, result;

	printf("n을 입력하세요: ");
	scanf("%d", &n);
	result = addEven(n);
	printf("1부터 %d까지의 짝수의 합은 %d입니다.\n", n, result);

	return 0;
}

int addEven(int n)
{
	if (n <= 1)
		return 0;
	else if (n % 2 != 0)
		return addEven(n - 1);
	else
		return n + addEven(n - 2);
}
