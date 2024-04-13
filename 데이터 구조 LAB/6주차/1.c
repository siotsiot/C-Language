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

void reverse(char str[])
{
    stack_Type s;
    init(&s);

    // push
    int i = 0;
    while (str[i] != '\0')
    {
        push(&s, str[i]);
        i++;
    }

    // pop
    while (!is_empty(s))
        printf("%c", pop(&s));
}

int main(void)
{
    char str[] = "abcdefgh";
    reverse(str);
    return 0;
}
