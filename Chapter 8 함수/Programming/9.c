#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int coin(void);

int main(void)
{
    int num, value;
    
    while(1)
    {
        printf("앞(0) 또는 뒤(1)를 선택하시오(종료는 -1): ");
        scanf("%d", &num);
        
        if (num == -1)
            break;
        
        value = coin();
        if (value == num)
            printf("사용자가 이겼습니다.\n");
        else
            printf("컴퓨터가 이겼습니다.\n");
    }
    
    return 0;
}

int coin(void)
{
    srand(time(NULL));
    return rand() % 2;
}
