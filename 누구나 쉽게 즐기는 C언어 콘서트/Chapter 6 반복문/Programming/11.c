#include <stdio.h>

int main(void)
{
    int i, j, num;
    
    for (i = 1; i <= 10; i++)
    {
        printf("데이터를 입력하시오: ");
        scanf("%d", &num);
        if (num >= 1 && num <= 50)
        {
            for (j = 1; j <= num; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}
