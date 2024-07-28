#include <stdio.h>

int main(void)
{
    char signal;
    
    printf("문자를 입력하시오: ");
    scanf("%c", &signal);
    
    if (signal == 'R' || signal == 'r')
        printf("정지!\n");
    else if (signal == 'G' || signal == 'g')
        printf("진행!\n");
    else if (signal == 'Y' || signal == 'y')
        printf("주의!\n");
    
    return 0;
}
