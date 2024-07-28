#include <stdio.h>

int main(void)
{
    int num;
    
    for (num = 0; num < 128; num++)
        printf("%d: %c\n", num, num);
    
    return 0;
}
