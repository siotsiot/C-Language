#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dice(void);

int main(void)
{
    int a[6] = { 0 };
    int i;
    srand(time(NULL));
    
    for (i = 0; i < 6; i++)
        a[i] = dice();
    
    printf("사용자 주사위=(%d, %d, %d)=%d\n", a[0], a[1], a[2], a[0] + a[1] + a[2]);
    printf("컴퓨터 주사위=(%d, %d, %d)=%d\n", a[3], a[4], a[5], a[3] + a[4] + a[5]);

    if (a[0] + a[1] + a[2] > a[3] + a[4] + a[5])
        printf("사용자 승리\n");
    else if (a[0] + a[1] + a[2] == a[3] + a[4] + a[5])
        printf("비겼습니다.\n");
    else
        printf("컴퓨터 승리\n");
    
    return 0;
}

int dice(void)
{
    return rand() % 6;
}
