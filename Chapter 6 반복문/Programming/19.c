#include <stdio.h>

int main(void)
{
    int repeat, i, n = 1;
    double pi = 0.0, denominator = 1.0;
    
    printf("반복횟수: ");
    scanf("%d", &repeat);
    
    for (i = 1; i <= repeat; i++)
    {
        if (n % 2 == 1)
        {
            pi += (4.0 / denominator);
            n++;
            denominator += 2.0;
        }
        else
        {
            pi -= (4.0 / denominator);
            n++;
            denominator += 2.0;
        }
    }
    
    printf("Pi = %lf\n", pi);
    
    return 0;
}
