#include <stdio.h>
void show_digit(int);

int main(void)
{
    int num;
    
    printf("정수를 입력하시오: ");
    scanf("%d", &num);
    show_digit(num);
    printf("\n");
    
    return 0;
}

void show_digit(int x)
{
    if (x == 0)
        return;

    show_digit(x / 10);
    printf("%d ", x % 10);
}
