#include <stdio.h>

int main(void)
{
    int num, i, fib = 0, fib_1 = 0, fib_2 = 1;
    
    printf("몇 번째 항까지 구할까요? ");
    scanf("%d", &num);
    
    for (i = 1; i <= num + 1; i++)
    {
        printf("%d, ", fib);
        fib_1 = fib_2;
        fib_2 = fib;
        fib = fib_1 + fib_2;
    }
    
    printf("\n");
    
    return 0;
}
