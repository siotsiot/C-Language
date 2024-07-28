#include <stdio.h>
#include <math.h>

int main(void)
{
    int year;
    double init, interest, money;
    
    printf("초기저금액: ");
    scanf("%lf", &init);
    printf("이율: ");
    scanf("%lf", &interest);
    printf("저축기간: ");
    scanf("%d", &year);
    
    money = init * pow((1.0 + interest), (double)year);
    
    printf("%d년 후의 원리금=%lf\n", year, money);
    
    return 0;
}
