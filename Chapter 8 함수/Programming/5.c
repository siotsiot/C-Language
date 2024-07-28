#include <stdio.h>
int check_prime(int);

int main(void)
{
    int i;
    
    for (i = 1; i <= 100; i++)
    {
        if (check_prime(i) == 1)
            printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}

int check_prime(int n)
{
    int is_prime = 1;
    
    if (n == 1)
        return 0;
    
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            is_prime = 0;
            break;
        }
    }
    return is_prime;
}
