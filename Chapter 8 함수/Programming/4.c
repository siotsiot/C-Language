#include <stdio.h>
int get_divisor(int, int);

int main(void)
{
    int value, n, i;
    
    printf("정수를 입력하시오: ");
    scanf("%d", &n);
    
    printf("%d의 약수: ", n);
    for (i = 1; i <= n; i++)
    {
        value = get_divisor(n, i);
        if (value != 0)
            printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}

int get_divisor(int num, int i)
{
    if (num % i == 0)
        return 1;
    else
        return 0;
}
