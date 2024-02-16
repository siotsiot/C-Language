#include <stdio.h>

int balance = 10000; // 잔고는 전역 변수로 선언.

int main(void)
{
    int select, deposit, withdraw, flag = 0;
    
    printf("**********Welcome to 콘서트 ATM**********\n");
    
    while(1)
    {
        printf("****하나를 선택하시오****\n");
        printf("<1> 잔고 확인\n");
        printf("<2> 입금\n");
        printf("<3> 인출\n");
        printf("<4> 종료\n");
        scanf("%d", & select);
        
        switch (select)
        {
            case 1:
                printf("현재 잔고는 %d원입니다.\n", balance);
                break;
            
            case 2:
                printf("****입금 금액을 입력하시오\n");
                scanf("%d", &deposit);
                printf("\n현재 잔고는 %d원입니다.\n", balance += deposit);
                break;
                
            case 3:
                while(1)
                {
                    printf("****인출 금액을 입력하시오\n");
                    scanf("%d", &withdraw);
                    if (balance >= withdraw )
                    {
                        printf("현재 잔고는 %d원입니다.\n", balance -= withdraw);
                        break;
                    }
                    else
                        printf("돈이 부족합니다.\n");
                }
                break;
                
            case 4:
                printf("프로그램을 종료합니다.\n");
                flag = 1;
                break;
                
            default:
                break;
        }
        
        if (flag == 1)
            break;
    }
    printf("프로그램이 종료됐습니다.\n");
    
    return 0;
}
