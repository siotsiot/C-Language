#include <stdio.h>
int calculator(int n);

int main(void)
{
    int num, result;
    
    printf("정수를 입력하시오: ");
    scanf("%d", &num);
    result = calculator(num);
    printf("%d\n", result);
    
    return 0;
}

int calculator(int n)
{
    if (n == 0)
        return 0;
    else
        return (n * n * n) + calculator(n - 1);
}
