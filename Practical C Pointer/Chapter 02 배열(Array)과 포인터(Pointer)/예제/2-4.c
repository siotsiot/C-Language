// 1차원 배열 주소

#include <stdio.h>

int main(void)
{
	char name[5] = "king";
	int score[5] = { 10, 20 ,30, 40, 50 };
	int i;

	printf("%p, %p\n", name, &name[0]);
	printf("%c, %c, %c, %c\n", name[0], name[1], name[2], name[3]);
	printf("%c, %c, %c, %c\n\n", *(name + 0), *(name + 1), *(name + 2), *(name + 3));

	printf("%p, %p\n", score, &score[0]);
	printf("%d, %d, %d, %d\n", score[0], score[1], score[2], score[3]);
	printf("%d, %d, %d, %d\n", *(score + 0), *(score + 1), *(score + 2), *(score + 3));

	return 0;
}
