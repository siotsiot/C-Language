#include <stdio.h>
int menu(void);
void check_balance(void);
void deposit(void);
void withdraw(void);
int quit(void);

int balance = 10000; // 잔고는 전역 변수로 선언.

int main(void)
{
    int select, flag = 0;
    
    printf("**********Welcome to 콘서트 ATM**********\n");
    
    do
    {
        select = menu();
        
        switch (select)
        {
            case 1:
                check_balance();
                break;
            
            case 2:
                deposit();
                break;
                
            case 3:
                withdraw();
                break;
                
            case 4:
                flag = quit();
                break;
                
            default:
                break;
        }
    } while (flag != 1);
    
    printf("프로그램이 종료됐습니다.\n");
    
    return 0;
}

int menu(void) // 메뉴 표시
{
    int select;
    printf("****하나를 선택하시오****\n");
    printf("<1> 잔고 확인\n");
    printf("<2> 입금\n");
    printf("<3> 인출\n");
    printf("<4> 종료\n");
    scanf("%d", &select);
    
    return select;
}

void check_balance(void) // 잔고 확인
{
    printf("현재 잔고는 %d원입니다.\n", balance);
}

void deposit(void) // 입금
{
    int deposit;
    
    printf("****입금 금액을 입력하시오\n");
    scanf("%d", &deposit);
    printf("\n현재 잔고는 %d원입니다.\n", balance += deposit);
}

void withdraw(void) // 인출
{
    int withdraw;
    
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
}

int quit(void)
{
    printf("프로그램을 종료합니다.\n");
    return 1;
}
