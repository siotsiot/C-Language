#include <stdio.h>

int main(void)
{
    int day, airplane, hotel, pocket_money, total;
    
    printf("여행은 몇 박인가요?: ");
    scanf("%d", &day);
    printf("항공권 가격: ");
    scanf("%d", &airplane);
    printf("호텔 1박 가격: ");
    scanf("%d", &hotel);
    printf("하루에 필요한 용돈: ");
    scanf("%d", &pocket_money);
    
    total = airplane + (hotel * day) + ((day + 1) * pocket_money);
    
    printf("=========================\n");
    printf("총 여행 비용: %d\n", total);
    printf("=========================\n");
    
    return 0;
}
