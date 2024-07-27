#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int user, computer;
    
    printf("가위, 바위, 보 게임에 오신 것을 환영합니다.\n");
    printf("하나를 선택하세요(가위-0, 바위-1, 보-2): ");
    scanf("%d", &user);
    
    srand(time(NULL));
    computer = rand() % 3;
    
    if ((user + 1) % 3 == computer) // user값에 1을 더한 값이 computer값과 같으면 컴퓨터 승.
        printf("사용자: %d\n컴퓨터: %d\n컴퓨터 승!\n", user, computer);
    else if (user == computer)
        printf("사용자: %d\n컴퓨터: %d\n비겼습니다!\n", user, computer);
    else
        printf("사용자: %d\n컴퓨터: %d\n사용자 승!\n", user, computer);
    
    return 0;
}
