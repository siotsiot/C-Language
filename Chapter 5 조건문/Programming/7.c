#include <stdio.h>

int main(void)
{
    int a, b, c;
    
    printf("삼각형의 세 변을 입력하시오: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a == b || b == c| a == c)
        printf("이등변삼각형\n");
    else if (a == b && b== c)
        printf("정삼각형\n");
    
    return 0;
}
