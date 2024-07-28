#include <stdio.h>

int main(void)
{
    double num;
    
    printf("실수를 입력하시오: ");
    scanf("%lf", &num);
    printf("지수 형식으로는 %le형식입니다.\n", num); // %le는 double형인 부동소수점을 지수형식으로 출력할 때 사용하는 형식지정자임.
    
    return 0;
}
