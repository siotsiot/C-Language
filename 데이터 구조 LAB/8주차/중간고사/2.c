#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
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

int print_paren(char str[])
{
    stack_Type s;
    init(&s);
    char ch;
    int i = 0, count = 0, flag = 1;

    while ((ch = str[i++]) != '\0')
    {
        if (ch == '(')
        {
            printf("%d", ++count);
            push(&s, count);
        }
        else if (ch == ')' && !is_empty(s))
            printf("%d", pop(&s));
        else
            flag = 0;
    }

    return flag;
}

int main(void)
{
    char s1[] = "((())(()))";
    char s2[] = "((((()";
    char s3[] = "())(()))";

    if (print_paren(s1))
        printf("\nParentheses are matched\n");
    else
        printf("\nParentheses are NOT matched\n");

    if (print_paren(s2))
        printf("\nParentheses are matched\n");
    else
        printf("\nParentheses are NOT matched\n");

    if (print_paren(s3))
        printf("\nParentheses are matched\n");
    else
        printf("\nParentheses are NOT matched\n");

    return 0;
}
