// 변수와 메모리

#include <stdio.h>

int main(void)
{
	char ch;			// 문자변수 선언
	int num;			// 정수형 변수 선언
	float f_num;		// 단정도 실수형 변수 선언
	double d_num;		// 배정도 실수형 변수 선언
	
	ch = 'A';			// 문자상수 할당(치환)
	num = 5000;			// 정수상수 할당
	f_num = 3.14;		// 실수상수 할당
	d_num = f_num * 2;	// 연산식 할당

	printf("%d, %d, %d, %d\n", sizeof(ch), sizeof(num), sizeof(f_num), sizeof(d_num));
	printf("%c, %d, %.2f, %.2lf\n", ch, num, f_num, d_num); // 변수 값 출력

	return 0;
}
