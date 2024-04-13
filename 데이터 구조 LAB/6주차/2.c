#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    char stk[MAX_SIZE];
    int top;
} stack_Type;

void init(stack_Type* s)
{
    s->top = -1;
}

int is_empty(stack_Type s) // 비어있으면 true, 비어있지 않으면 false
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

int is_full(stack_Type s)
{
    if (s.top == (MAX_SIZE - 1))
        return 1;
    else
        return 0;
}

void push(stack_Type* s, char ch)
{
    if (is_full(*s) != 1)
    {
        s->top++;
        s->stk[s->top] = ch;
    }
    else
        printf("스택이 가득 찼습니다.\n");
}

char pop(stack_Type* s)
{
    if (is_empty(*s))
        printf("스택이 비었습니다.\n");
    else
        return s->stk[s->top--];
}

char peek(stack_Type s)
{
    if (is_empty(s))
        printf("스택이 비었습니다.\n");
    else
        return s.stk[s.top];
}

int paren_test(char exp[])
{
    int i = 0;
    char ch;
    stack_Type s;
    init(&s);

    while ((ch = exp[i++]) != '\0') // 식의 마지막(NULL 문자)인지 판별
    {
        switch (ch)
        {
            case '(':
                if (!is_full(s))
                    push(&s, ch);
                break;

            case ')':
                if (is_empty(s) || (pop(&s) != '(')) // 스택이 비었거나 왼쪽 괄호가 아닌 경우
                    return 0;
                break;
        }
    }

    if (is_empty(s)) // 스택이 비었을 때
    {
        printf("\"%s\" ", exp);
        printf("is Balanced.");
        return 1;
    }
       
    else // 스택이 비어있지 않을 때
    {
        printf("\"%s\" ", exp);
        printf("is Not Balanced.");
        return 0;
    }
}

int main(void)
{
    char str[] = "((())(()))";
    paren_test(str);
    return 0;
}
