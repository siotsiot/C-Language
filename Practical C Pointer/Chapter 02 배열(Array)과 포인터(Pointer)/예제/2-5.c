// 2차원 배열 주소

#include <stdio.h>

int main(void)
{
	char names[3][5] = { "sun", "park", "kim" };
	int score[3][5] = { 10, 20 ,30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };

	printf("%d, %d ,%d\n", sizeof(names), sizeof(names[0]), sizeof(names[0][0]));
	printf("%p, %p, %p, %p, %p\n\n", names, names[0], names[1], names[2], &names[0][0]);

	printf("%d, %d, %d\n", sizeof(score), sizeof(score[0]), sizeof(score[0][0]));
	printf("%p, %p, %p, %p, %p\n", score, score[0], score[1], score[2], &score[0][0]);

	return 0;
}
