// 포인터 식 2

#include <stdio.h>

int main(void)
{
	double dnum, * p_dnum;
	
	dnum = 3.5;
	p_dnum = &dnum;

	printf("변수의 값과 시작 주소 출력\n");
	printf("%lf, %p\n", dnum, &dnum);

	printf("\ndouble형 p_dnum 포인터 변수의 연산\n");
	printf("%p, %p\n", p_dnum, p_dnum + 1);

	printf("\ndouble형 p_dnum 포인터 변수의 연산\n");
	printf("%p, %p\n", (char*)p_dnum, (char*)p_dnum + 1);

	printf("\nint형 p_dnum 포인터 변수의 연산\n");
	printf("%p, %p\n", (int*)p_dnum, (int*)p_dnum + 1);

	return 0;
}
