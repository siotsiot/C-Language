#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int fibo_rec(int);
int fibo_iter(int);

int main(void)
{
	clock_t start, finish;
	double duration;
	int n, result;

	printf("몇 번째 피보나치 수를 볼까요?: ");
	scanf("%d", &n);
	start = clock();
	result = fibo_iter(n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("fibo_rec(): %.3lf 초입니다.\n", duration);
	printf("%d번째 피보나치 수는 %d입니다\n", n, result);

	return 0;
}

int fibo_rec(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fibo_rec(n - 2) + fibo_rec(n - 1);
}

int fibo_iter(int n)
{
	int pre_num = 0;
	int med_num = 1;
	int next_num = 1;

	if (n == 1)
		return pre_num;
	else if (n == 2)
		return med_num;
	else
		for (int i = 3; i <= n; i++)
		{
			next_num = pre_num + med_num;
			pre_num = med_num;
			med_num = next_num;
		}
	return next_num;
}
