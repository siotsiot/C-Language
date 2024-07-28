#include <stdio.h>

int main(void)
{
    int i, size, sum = 0;
    int a[100] = { 0 };
    
    printf("입력할 정수의 개수: ");
    scanf("%d", &size);
    
    for (i = 0; i < size; i++)
    {
        printf("%d번째 요소를 입력하시오: ", i);
        scanf("%d", &a[i]);
        sum += a[i];
    }
    
    printf("합=%d\n", sum);
    
    return 0;
}
