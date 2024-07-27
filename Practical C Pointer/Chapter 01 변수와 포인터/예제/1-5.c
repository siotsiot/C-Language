// 포인터 변수의 이해

#include <stdio.h>

int main(void)
{
	char ch, * p_ch; // 변수와 포인터 변수 선언
	int num, * p_num;
	
	ch = 'A'; num = 5000;
	p_ch = &ch; p_num = &num; // 포인터 변수에 변수의 시작 주소 저장

	printf("변수의 값 출력\n");
	printf("%c, %d, %p, %p\n", ch, num, &ch, &num);

	printf("\n포인터 변수가 보관하고 있는 주소\n");
	printf("%p, %p\n", p_ch, p_num);

	printf("\n포인터 변수가 참조하는 데이터\n");
	printf("%c, %d\n", *p_ch, *p_num);

	printf("\n변수와 포인터 변수의 메모리 할당 크기\n");
	printf("%d, %d, %d, %d\n", sizeof(ch), sizeof(num), sizeof(p_ch), sizeof(p_num));

	return 0;
}
