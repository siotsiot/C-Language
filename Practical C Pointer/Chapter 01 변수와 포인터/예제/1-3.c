// 주소의 가감산

#include <stdio.h>

int main(void)
{
	char ch; int num; float f_num; double d_num;

	ch = 'A'; num = 5000; f_num = 3.14; d_num = f_num * 2;

	printf("%c, %d, %.2f, %.2lf \n", ch, num, f_num, d_num);
	printf("%p, %p, %p, %p \n", &ch, &num, &f_num, &d_num);

	printf("%c, %d, %.2f, %.2lf \n", ch + 1, num + 1, f_num + 1, d_num + 1);	// 값의 증가
	printf("%p, %p, %p, %p \n", &ch + 1, &num + 1, &f_num + 1, &d_num + 1);		// 주소의 증가

	return 0;
}
