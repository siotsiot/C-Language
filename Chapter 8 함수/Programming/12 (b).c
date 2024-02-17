#include <stdio.h>
void save(int amout);

int main(void)
{
    int n;
    
    while(1)
    {
        printf("얼마를 저축하시겠습니까?(종료는 -1): ");
        scanf("%d", &n);
        if (n == -1)
            break;
        save(n);
    }
    
    return 0;
}

void save(int amount)
{
    static int money = 0;
    printf("지금까지의 저축액은 %d입니다.\n", money += amount);
}
