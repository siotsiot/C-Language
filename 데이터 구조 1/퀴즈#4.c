#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
typedef struct {
    element stk[MAX_SIZE];
    int top;
} stack_Type;

// 전역 변수로 선언
stack_Type stk1, stk2;

void init(stack_Type* stki)
{
    stki->top = -1;
}

int is_empty(stack_Type stki)
{
    return (stki.top == -1);
}

void push(stack_Type* stki, element e)
{
    stki->stk[++(stki->top)] = e;
}

element pop(stack_Type* stki)
{
    if (!is_empty(*stki))
        return stki->stk[(stki->top)--];
    else
    {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
}

element peek(stack_Type e)
{
    if (!is_empty(e))
        return e.stk[(e.top)];
    else
    {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
}

void enqueue(element e)
{
    push(&stk1, e);
}

int dequeue()
{
    if (stk1.top == -1 && stk2.top == -1)
    {
        fprintf(stderr, "큐가 비었습니다.\n");
        exit(1);
    }
    
    while (stk1.top != -1)
    {
        int tmp = pop(&stk1);
        push(&stk2, tmp);
    }

    return pop(&stk2);
}

void fibonacci_numbers(int n)
{
    int i = 0, a = 0, b = 1, c;
    enqueue(a);
    enqueue(b);

    while(1)
    {
        c = a + b;
        if (c > n)
            break;
        else
        {
            enqueue(c);
            a = b;
            b = c;
        }
    }
}

int main(void)
{
    int n = 21;
    init(&stk1);
    init(&stk2);
    
    fibonacci_numbers(n);
    int r = stk1.top;

    for (int i = 0; i <= r; i++)
        printf("%d ", dequeue());

    return 0;
}
