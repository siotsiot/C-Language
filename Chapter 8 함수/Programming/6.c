#include <stdio.h>
int get_power(int);

int main(void)
{
    int i;
    
    for (i = 0; i <= 10; i++)
    {
        printf("%d ", get_power(i));
    }
    printf("\n");
    
    return 0;
}

int get_power(int n)
{
    int value = 1;
    
    for (int i = 0; i < n; i++)
    {
        value *= 3;
    }
    return value;
}
