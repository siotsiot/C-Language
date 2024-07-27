// 2차원 배열 요소에 접근하기

#include <stdio.h>

int main(void)
{
	char names[3][5] = { "sun", "park", "kim"};
	int score[3][5] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
	
	int i, j;

	printf("names배열의 전체 크기: %d, score배열의 전체 크기: %d\n", sizeof(names), sizeof(score));

	printf("names배열의 하나의 원소 크기: %d, score배열의 하나의 원소 크기: %d\n", sizeof(names[0][0]), sizeof(score[0][0]));

	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			printf("name[%d][%d]:%c, %p\n", i, j, names[i][j], &names[i][j]);
	printf("\n");

	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			printf("score[%d][%d]:%d, %p\n", i, j, score[i][j], &score[i][j]);

	return 0;
}
