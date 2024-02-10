#include <stdio.h>

int main(void)
{
    double num;
    
    printf("지수형식으로 실수를 입력하시오: ");
    scanf("%le", &num);
    printf("지수 형식으로는 %lf형식입니다.\n", num);
    
    return 0;
}
