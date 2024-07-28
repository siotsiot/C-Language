#include <stdio.h>

int main(void)
{
    int day_of_week;
    
    printf("요일을 0(일요일)에서 6까지의 정수로 입력하시오: ");
    scanf("%d", &day_of_week);
    
    if (day_of_week >= 1 && day_of_week <= 5)
        printf("평일입니다.\n");
    else
        printf("주말입니다.\n");
    
    return 0;
}
