#include <stdio.h>

int main(void)
{
    int age;
    
    printf("나이를 입력하시오: ");
    scanf("%d", &age);
    printf("내년이면 %d살이 되시는군요.\n", age + 1);
    
    return 0;
}
