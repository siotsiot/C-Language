#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, num;
    int a[6] = { 0 };
    
    srand(time(NULL));
    printf("=======================\n");
    printf("주사위면            빈도\n");
    printf("=======================\n");
           
    for (i = 0; i < 60000; i++)
    {
        num = rand() % 6;
        a[num]++;
    }
    
    for (i = 0; i < 6; i++)
    {
        printf("  %d              %d\n", i + 1, a[i]);
    }
    
    return 0;
}
