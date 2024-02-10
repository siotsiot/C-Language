#include <stdio.h>

int main(void)
{
    short age, id;
    int num;
    double star;
    char c;
    
    printf("나이를 입력하시오: ");
    scanf("%hi", &age);
    printf("나이: %d\n", age);
    
    printf("직원 아이디를 입력하시오: ");
    scanf("%hi", &id);
    printf("아이디: %d\n", id);
    
    printf("생산량을 입력하시오: ");
    scanf("%d", &num);
    printf("생산량: %d\n", num);
    
    printf("별의 개수를 입력하시오: ");
    scanf("%lf", &star);
    printf("별의 개수: %e\n", star);
    
    getchar(); // 부동소수점을 입력할 때 숫자를 입력한 후에 엔터키를 쳐야하는데, 이 엔터키가 줄바꿈 문자로 바뀌어서 버퍼에 남아있어서 getchar()로 없앰.
    
    printf("글자를 입력하시오: ");
    scanf("%c", &c);
    printf("글자: %c\n", c);
    
    return 0;
}
