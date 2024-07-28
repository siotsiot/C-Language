#include <stdio.h>

int main(void)
{
    char a, b, c;
    
    printf("문자를 입력하시오: ");
    scanf("%c %c %c", &a, &b, &c);
    
    printf("문자: %c %c %c\n", c, b, a);
    
    return 0;
}
