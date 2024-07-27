#include <stdio.h>

int main(void)
{
    int x, y, z;
    
    printf("정수를 입력하시오 : ");
    scanf("%d", &x);
    printf("정수를 입력하시오 : ");
    scanf("%d", &y);
    printf("정수를 입력하시오 : ");
    scanf("%d", &z);
    
    printf("평균은 %d입니다.\n", (x + y + z) / 3);
    
    return 0;
}
