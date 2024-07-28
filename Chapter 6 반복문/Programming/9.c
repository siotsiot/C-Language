#include <stdio.h>

int main(void)
{
    int count = 0;
    char c;
    
    while(c != '.')
    {
        printf("문자를 입력하시오: (종료 .): ");
        c = getchar();
        getchar(); // getchar() 함수는 줄바꿈 문자인 버퍼를 포함하기 때문에 getchar()을 입력해서 줄바꿈 문자를 없앤다. (117p 참고)
        if (c == 'a')
            count++;
    }
    
    printf("a의 개수 = %d\n", count);
    
    return 0;
}
