#include <stdio.h>

int main(void)
{
	int a[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

	int* p = a;

	printf("배열 a의 요소: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", *(p+i));
  
	return 0;
}
