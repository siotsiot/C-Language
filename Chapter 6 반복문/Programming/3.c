#include <stdio.h>

int main(void)
{
    int num, num1, star, count = 6;
    
    for (num = 1; num <= 7; num++)
    {
        for (num1 = 1; num1 <= num; num1++)
        {
            printf("%d", num1);
        }
        
        for (star = count; star >= 0; star--)
        {
            printf("*");
        }
        count--;
        printf("\n");
    }
    
    return 0;
}
