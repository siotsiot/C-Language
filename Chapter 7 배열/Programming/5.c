#include <stdio.h>

int main(void)
{
    int i, j, sum = 0;
    int a[3][3] = { { 30, 10, 11 }, { 40, 90, 32 }, { 70, 65, 56 } };
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum += a[i][j];
        }
        printf("학번 %d: %d\n", i + 1, sum / 3);
        sum = 0;
    }
    
    return 0;
}
