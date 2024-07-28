#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int user, computer, stick = 12, flag = 0;
    
    srand(time(NULL));
    
    while (1)
    {
        printf("현재 스틱의 개수 : %d\n", stick);
        printf("몇 개의 스틱을 가져가시겠습니까? : ");
        scanf("%d", &user);
        
        stick -= user;
        if (stick == 0)
        {
            flag = 0;
            break;
        }
        
        computer = (rand() % 3) + 1;
        
        if (stick < computer)
            computer = stick;
        
        printf("**컴퓨터는 %d개의 스틱을 가져갔습니다.\n\n", computer);
        stick -= computer;
        
        if (stick == 0)
        {
            flag = 1;
            break;
        }
    }
    
    if (flag == 0)
        printf("컴퓨터 승리!\n");
    else
        printf("사용자 승리!\n");
    
    return 0;
}
