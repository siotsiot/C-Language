#include <stdio.h>
int menu(void);
void save(int);
void draw(int);
int money = 0;

int main(void)
{
    int cash, flag = 0;
    
    do {
        switch (menu())
        {
            case 1:
                printf("얼마를 저축하시겠습니까?: ");
                scanf("%d", &cash);
                save(cash);
                break;
            case 2:
                printf("얼마를 인출하시겠습니까?: ");
                scanf("%d", &cash);
                draw(cash);
                break;
            case 3:
                flag = 1;
            default:
                break;
        }
    } while (flag != 1);
    
    return 0;
}

int menu(void)
{
    int menu;
    printf("원하는 항목을 고르시오.\n");
    printf("1. 저축\n");
    printf("2. 인출\n");
    printf("3. 종료\n");
    scanf("%d", &menu);
    return menu;
}

void save(int amount)
{
    printf("지금까지의 저축액은 %d원입니다.\n", money += amount);
}

void draw(int amount)
{
    printf("잔액은 %d원입니다.\n", money -= amount);
}
