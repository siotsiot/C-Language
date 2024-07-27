#include <stdio.h>

int main(void)
{
    int num, sum = 0;
    
    while (1)
    {
        printf("정수를 입력하시오: ");
        scanf("%d", &num);
        if (num == 0)
            break;
        sum += num;
        
    }
    printf("합계=%d\n", sum);
    
    return 0;
}
