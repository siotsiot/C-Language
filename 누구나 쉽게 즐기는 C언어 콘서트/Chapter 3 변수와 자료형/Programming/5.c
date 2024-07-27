#include <stdio.h>

int main(void)
{
    char ch;
    
    printf("문자를 입력하시오: ");
    ch = getchar();
    printf("아스키 코드: %d\n", ch);
    
    return 0;
}
