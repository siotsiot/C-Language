#include <stdio.h>

int main(void)
{
    int num;
    
    for (num = 1; num <= 100; num++)
    {
        if (num % 3 == 0)
            printf("%d ", num);
    }
    
    printf("\n");
    
    return 0;
}
