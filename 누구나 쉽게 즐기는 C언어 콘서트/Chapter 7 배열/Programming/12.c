#include <stdio.h>

int main(void)
{
    int a[100] = { 0 };
    int i, num, delete;
    
    printf("입력할 정수의 개수(100개 이내로): ");
    scanf("%d", &num);
    
    for (i = 0; i < num; i++)
    {
        printf("%d번째의 요소를 입력하시오: ", i);
        scanf("%d", &a[i]);
    }
    
    printf("\n삭제할 위치: ");
    scanf("%d", &delete);
    
    for (i = delete; i < num; i++)
    {
        a[i] = a[i + 1];
    }
    printf("새로운 배열: ");
    for (i = 0; i < (num - delete); i++)
        printf("%d", a[i]);
    printf("\n");
    
    return 0;
}
