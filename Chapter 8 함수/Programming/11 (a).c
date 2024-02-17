#include <stdio.h>
void add (int x, int y);
void minus (int x, int y);
void multiple (int x, int y);
void divide (int x, int y);

int main(void)
{
    int a, b;
    char op;
    
    do {
        printf("연산을 입력하시오(종료는 Ctrl-Z 또는 command-.): ");
        scanf("%d %c %d", &a, &op, &b);
        
        switch (op)
        {
            case '+':
                add(a, b);
                break;
            case '-':
                minus(a, b);
                break;
            case '*':
                multiple(a, b);
                break;
            case '/':
                divide(a, b);
                break;
            default:
                break;
        }
    } while (1);
    
    return 0;
}

void add(int x, int y)
{
    static int add_cnt = 0;
    add_cnt++;
    printf("덧셈은 총 %d번 호출되었습니다.\n", add_cnt);
    printf("연산 결과: %d\n", x + y);
}

void minus(int x, int y)
{
    static int minus_cnt = 0;
    minus_cnt++;
    printf("뺄셈은 총 %d번 호출되었습니다.\n", minus_cnt);
    printf("연산 결과: %d\n", x - y);
}

void multiple(int x, int y)
{
    static int multiple_cnt = 0;
    multiple_cnt++;
    printf("곱셈은 총 %d번 호출되었습니다.\n", multiple_cnt);
    printf("연산 결과: %d\n", x * y);
}

void divide(int x, int y)
{
    static int divide_cnt = 0;
    divide_cnt++;
    printf("나눗셈은 총 %d번 호출되었습니다.\n", divide_cnt);
    printf("연산 결과: %d\n", x / y);
}
