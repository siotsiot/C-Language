// 1차원 배열을 포인터 변수로 접근하기

#include <stdio.h>

int main(void)
{
	int score[5] = { 10, 20, 30, 40 };
	int* ptr, i;

	printf("score 배열의 크기: %d, 포인터 변수의 크기: %d\n", sizeof(score), sizeof(ptr));

	ptr = score; // 배열의 시작 주소 대입
	printf("score 시작 주소: %p, ptr에 저장된 주소: %p\n", score, ptr);

	// 배열 원소를 출력한다
	printf("%d, %d, %d\n", score[0], score[1], score[2]);
	printf("%d, %d, %d\n", *(ptr + 0), *(ptr + 1), *(ptr + 2));
	printf("%d, %d, %d\n", *(score + 0), *(score + 1), *(score + 2));
	printf("%d, %d, %d\n", ptr[0], ptr[1], ptr[2]);

	printf("%p, %p, %p, %p\n", score + 1, ptr + 1, &score[1], &ptr[1]);

	return 0;
}
