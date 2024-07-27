// 포인터 변수의 자료형, 1

#include <stdio.h>

int main(void)
{
	char ch;
	char* p_ch;

	ch = 'A'; p_ch = &ch;

	printf("%c, %p\n", ch, &ch);

	printf("\n%c, %p\n", *p_ch, p_ch);

	*p_ch = *p_ch + 1;
	printf("\n%c, %p\n", *p_ch, p_ch);

	return 0;
}
