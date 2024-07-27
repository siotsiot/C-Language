// 포인터 식 1

#include <stdio.h>

int main(void)
{
	char ch, * p_ch;
	double dnum, * p_dnum;

	ch = 'A'; dnum = 3.5;
	p_ch = &ch; p_dnum = &dnum;

	printf("%c, %lf, %p, %p\n", ch, dnum, p_ch, p_dnum);

	ch++; dnum++;		// 값의 연산
	p_ch++; p_dnum++;	// 포인터의 연산

	printf("%c, %lf, %p, %p\n", ch, dnum, p_ch, p_dnum);

	return 0;
}
