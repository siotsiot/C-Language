// cast 연산자를 이용한 주소의 가감산

#include <stdio.h>

int main(void)
{
	char ch; int num; float f_num; double d_num;

	ch = 'A'; num = 5000; f_num = 3.14; d_num = f_num * 2;

	printf("\n모든 변수의 선두주소 출력\n");
	printf("%p, %p, %p, %p \n", &ch, &num, &f_num, &d_num);

	printf("\n주소를 변수의 자료형에 맞게 증감\n");
	printf("%p, %p, %p, %p \n", (char *)& ch + 1, (char*)&num + 1, (char*)&f_num + 1, (char*)&d_num + 1);

	printf("\n주소를 변수의 자료형에 맞게 증감\n");
	printf("%p, %p, %p, %p \n", (int *)&ch + 1, (int*)&num + 1, (int*)&f_num + 1, (int*)&d_num + 1);

	return 0;
}
