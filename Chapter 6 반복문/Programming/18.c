#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int money = 50, bet = 0, win = 0;
    
    printf("초기 금액 $%d\n", money);
    printf("목표 금액 $250\n");
    
    srand(time(NULL));
    
    while(bet <= 1000)
    {
        if ((double)rand() / RAND_MAX < 0.5)
        {
            money++;
            bet++;
            win++;
            if (money >= 250)
                break;
        }
        else
        {
            money--;
            bet++;
            if (money <= 0)
                break;
        }
    }
    
    printf("1000번 중 %d번 승리\n", win);
    printf("이긴 확률 = %lf\n", ((double)win / 1000.0) * 100.0);
    
    return 0;
}
