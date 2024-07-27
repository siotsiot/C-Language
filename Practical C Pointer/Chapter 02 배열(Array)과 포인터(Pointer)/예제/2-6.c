// 행 주소를 이용한 문자열 입출력

#include <stdio.h>

int main(void)
{
	char names[3][5] = {"sun", "park", "kim"};
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("%d, input name ? ", i + 1);
		gets(names[i]); // 각 행 주소를 시작으로 문자열 지정
	}

	for (i = 0; i < 3; i++)
		printf("%s, ", names[i]); // 행 주소부터 '\0'문자를 만날 때까지 출력
	printf("\n");

	return 0;
}
