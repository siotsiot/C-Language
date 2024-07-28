#include <stdio.h>

int main(void)
{
    int i, size;
    int a[100] = { 0 }; // 배열의 크기는 변수의 값이 못 들어가므로, 충분히 큰 상수로 지정.
    
    printf("입력할 정수의 개수: ");
    scanf("%d", &size);
    
    for (i = 0; i < size; i++)
    {
        printf("%d번째 요소를 입력하시오: ", i);
        scanf("%d", &a[i]);
    }
    
    for (i = size - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
