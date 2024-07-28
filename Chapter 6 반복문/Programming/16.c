#include <stdio.h>

int main(void)
{
    int num, i, flag = 1;
    
    printf("정수를 입력하시오: ");
    scanf("%d", &num);
    
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            flag = 0;
            break;
        }
    }
    
    if (flag == 1)
        printf("%d은(는) 소수가 맞습니다.\n", num);
    else
        printf("%d은(는) 소수가 아닙니다.\n", num);
    
    return 0;
}
