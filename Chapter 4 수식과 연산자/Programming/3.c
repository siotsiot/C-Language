#include <stdio.h>

int main(void)
{
    double price, disc_rate, disc_price;
    
    printf("상품 가격을 입력하시오: ");
    scanf("%lf", &price);
    printf("할인률을 입력하시오: ");
    scanf("%lf", &disc_rate);
    
    disc_price = price * ((100 - disc_rate) / 100);
    
    printf("할인된 가격은 %.2lf입니다.\n", disc_price);
    
    return 0;
}
