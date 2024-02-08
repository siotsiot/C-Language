#include <stdio.h>

int main(void)
{
    int x, y, num, sum = 0;
    
    printf("시작정수: ");
    scanf("%d", &x);
    printf("종료정수: ");
    scanf("%d", &y);
    
    for (num = x; num <= y; num++)
    {
        sum += num;
    }
    
    
    printf("%d에서 %d까지의 합 = %d\n", x, y, sum);
    
    return 0;
}
