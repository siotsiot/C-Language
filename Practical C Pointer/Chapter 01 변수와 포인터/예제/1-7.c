// 포인터 변수의 자료형, 2

#include <stdio.h>

int main(void)
{
	char ch;
	int* p_ch;

	ch = 'A';
	p_ch = &ch;

	printf("변수의 값, 시작주소 출력\n");
	printf("%d, %p\n", ch, &ch);

	printf("\n포인터 변수가 참조하는 값, 포인터 변수에 저장된 주소 출력\n");
	printf("%d, %p,\n", *p_ch, p_ch);

	return 0;
}
