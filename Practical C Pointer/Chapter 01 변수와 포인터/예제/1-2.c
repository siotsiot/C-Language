// 변수와 메모리

#include <stdio.h>

int main(void)
{
	char ch; int num; float f_num; double d_num;

	ch = 'A'; num = 5000; f_num = 3.14; d_num = f_num * 2;

	printf("%p, %p, %p, %p \n", &ch, &num, &f_num, &d_num); // 변수의 선두 주소를 출력한다.

	return 0;
}
