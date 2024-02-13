#include <stdio.h>

int main(void)
{
    char code;
    
    printf("문자를 입력하시오: ");
    scanf("%c", &code);
    
    if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122))
        printf("알파벳입니다.\n");
    else if (code >= 48 && code <= 57)
        printf("숫자입니다.\n");
    else
        printf("특수문자입니다.\n");
//    
    return 0;
}
