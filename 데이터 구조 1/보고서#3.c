#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef char element;
typedef struct {
    char stk[MAX_SIZE];
    int top;
} stack_Type;

void init(stack_Type* s)
{
    s->top = -1;
}

int is_empty(stack_Type s)
{
    return (s.top == -1);
}

int is_full(stack_Type s)
{
    return (s.top == (MAX_SIZE - 1));
}

void push(stack_Type* s, element ch)
{
    if (!is_full(*s))
        s->stk[++(s->top)] = ch;
    else
    {
        fprintf(stderr, "스택이 가득 찼습니다.\n");
        exit(1);
    }
}

element pop(stack_Type* s)
{
    if (!is_empty(*s))
        return s->stk[(s->top)--];
    else
    {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
}

element peek(stack_Type s)
{
    if (!is_empty(s))
        return s.stk[(s.top)];
    else
    {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
}

int PIS(char op)
{
    switch (op)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '^':
            return 2;
    }

    return -1;
}

int PIE(char op)
{
    switch (op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '^':
            return 2;
        case '(':
            return 3;
        }

    return -1;
}

int is_operator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

char get_token(char exp[], int* pos) {
    char token = exp[(*pos)++];

    // 공백은 skip
    while (isspace(token)) {
        token = exp[(*pos)++];
    }

    return token;
}

void postfix(char exp[], char pexp[]) {
    stack_Type s;
    init(&s);
    int i = 0, j = 0;
    char top_op;
    char token;

    while ((token = get_token(exp, &i)) != '\0') {
        if (isdigit(token)) {
            pexp[j++] = token;
            // 연속된 숫자 처리
            while (isdigit(exp[i]))
                pexp[j++] = exp[i++];
            pexp[j++] = ' '; // 피연산자와 연산자 구분을 위해 공백 추가
        }
        else if (is_operator(token)) {
            while (!is_empty(s) && PIS(peek(s)) >= PIE(token))
                pexp[j++] = pop(&s);
            push(&s, token);
        }
        else if (token == '(')
            push(&s, token);
        else if (token == ')') {
            top_op = pop(&s);
            while (!is_empty(s) && top_op != '(') {
                pexp[j++] = top_op;
                top_op = pop(&s);
            }
        }
    }

    while (!is_empty(s))
        pexp[j++] = pop(&s);
    pexp[j] = '\0';
}

double compute(double x, char op, double y) {
    double result;
    switch (op)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '^':
            result = pow(x, y);
            return result;
        default:
            printf("유효하지 않은 연산자입니다.\n");
            return 0;
            break;
    }
}

double eval(element exp[])
{
    stack_Type s;
    init(&s);
    char ch;
    int i = 0;
    double result, op1, op2;

    while ((ch = exp[i++]) != '\0') {
        if (isdigit(ch))
        {
            int k = 0;
            char operand[MAX_SIZE];
            operand[k++] = ch;
            // 연속된 숫자 처리
            while (isdigit(exp[i]))
                operand[k++] = exp[i++];
            operand[k] = '\0';
            push(&s, atof(operand)); // 숫자 문자열을 double로 변환하여 스택에 push (atof 함수는 문자열을 부동소수점으로 변환)
        }
        else if (is_operator(ch))
        {
            op2 = pop(&s);
            op1 = pop(&s);
            result = compute(op1, ch, op2);
            push(&s, result);
        }
    }
    return pop(&s);
}

void get_exp(char* exp)
{
    printf("\n식 입력: ");
    fgets(exp, MAX_SIZE, stdin); // 식을 한 번에 받기 위해 fgets 사용
}

int main(void)
{
    char iexp[MAX_SIZE]; // 중위 식
    char pexp[MAX_SIZE]; // 후위 식
    int menu;

    do {
        printf("1. 계산기 실행\n");
        printf("2. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &menu);
        getchar(); // 버퍼 제거

        switch (menu) {
        case 1:
            get_exp(iexp);
            postfix(iexp, pexp);
            printf("%lf\n\n", eval(pexp));
            break;

        case 2:
            printf("\n계산기 프로그램이 종료되었습니다.\n");
            break;

        default:
            printf("잘못 입력했습니다. 다시 입력하세요.\n\n");
            break;
        }
    } while (menu != 2);

    return 0;
}
