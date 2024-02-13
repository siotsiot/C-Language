#include <stdio.h>

int main(void)
{
    int money, tmp, tax;
    
    printf("과세 표준을 입력하시오(만원): ");
    scanf("%d", &money);
    
    if (money > 8000)
    {
        tmp = money - 8000;
        tax = tmp * 0.35 + 8000 * 0.26;
    }
    else if (money > 4000 && money <= 8000)
    {
        tmp = money - 4000;
        tax = tmp * 0.26 + 4000 * 0.17;
    }
    else if (money > 1000 && money <= 4000)
    {
        tmp = money - 1000;
        tax = tmp * 0.17 + 1000 * 0.08;
    }
    else
    {
        tax = money * 0.08;
    }
    
    printf("소득세는 %d만원입니다.\n", tax);
    
    return 0;
}
