#include <stdio.h>

int main(void)
{
    int oil = 1000, num;
    char tank;
    
    printf("초기연료량: %d\n", oil);
    
    while(1)
    {
        printf("연료 충전은 +, 소모는 -로 입력해주세요: ");
        scanf("%c %d", &tank, &num);
        
        if (tank == '+')
        {
            oil += num;
            printf("현재 남아있는 양은 %d입니다.\n", oil);
        }
        else if (tank == '-')
        {
            oil -= num;
            printf("현재 남아있는 양은 %d입니다.\n", oil);
            if (oil <= 100)
            {
                printf("(경고) 연료가 10 이하입니다.\n");
                break;
            }
        }
    }
  
    return 0;
}
