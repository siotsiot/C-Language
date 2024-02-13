#include <stdio.h>

int main(void)
{
    char code;
    
    printf("문자를 입력하시오: ");
    scanf("%c", &code);
    
    if (code >= 65 && code <= 90)
        printf("대문자입니다.\n");
    else if (code >= 97 && code <= 122)
        printf("소문자입니다.\n");
    
    return 0;
}
