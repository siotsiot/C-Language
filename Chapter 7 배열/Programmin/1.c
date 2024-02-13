#include <stdio.h>
#define SIZE 12

int main(void)
{
    int i;
    int days[SIZE] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for (i = 1; i < SIZE; i++)
    {
        printf("%d월은 %d까지 있습니다.\n", i + 1, days[i]);
    }
    
    return 0;
}
