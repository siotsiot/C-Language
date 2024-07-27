// 1차원 배열 요소에 접근하기

#include <stdio.h>

int main(void)
{
	char name[5] = "king";
	int score[5] = { 10, 20, 30, 40 };
	int i;

	printf("name배열의 전체 크기: %d, score배열의 전체 크기: %d\n", sizeof(name), sizeof(score));

	printf("name배열의 하나의 원소 크기: %d, score배열의 하나의 원소 크기: %d\n", sizeof(name[0]), sizeof(score[0]));

	for (i = 0; i < 5; i++)
		printf("name[%d]:%c, %p\n", i, name[i], &name[i]);
	printf("\n");

	for (i = 0; i < 5; i++)
		printf("score[%d]:%d, %p\n", i, score[i], &score[i]);

	return 0;
}
