// 표준 라이브러리 함수를 이용한 배열 초기화와 복사

#include <stdio.h>

int main(void)
{
	int score[3][5] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
	int tmp[3][5], i, j;

	memmove(tmp, score, sizeof(tmp)); // score 배열을 tmp 배열에 복사
	
	printf("tmp 배열\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%4d", tmp[i][j]);
		printf("\n");
	}

	memset(score, 0, sizeof(tmp)); // score 배열을 0으로 초기화

	printf("\nscore 배열\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%4d", score[i][j]);
		printf("\n");
	}

	return 0;
}
