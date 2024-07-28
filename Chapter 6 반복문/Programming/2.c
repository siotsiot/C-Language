#include <stdio.h>

int main(void)
{
    int repeat, i;
    
    printf("몇 번이나 반복할까요?: ");
    scanf("%d", &repeat);
    
    for (i = 1; i <= repeat; i++)
        printf("안녕하세요?\n");
    
    return 0;
}
