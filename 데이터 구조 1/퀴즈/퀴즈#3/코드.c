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

int is_full(stack_Type s) // 가득 찼으면 true, 가득 안 차있으면 false
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

int remove(int num)
{
    stack_Type s;
    init(&s);
    int result = 0;

    // 처음에 스택에 숫자가 있는지 확인할 때 스택이 비어있으므로 출력되는 문구를 제거하고자 처음 값은 바로 넣었습니다.
    int first_num = num % 10; // 첫 번째 자릿수를 저장합니다.
    push(&s, first_num);

    while (num > 0) // num이 0보다 크면 반복
    {
        char lsn = num % 10;
        if (peek(s) != lsn) // 마지막 자리가 스택에 있는지 확인
            push(&s, lsn);
        num /= 10; // 자릿수 추출
    }

    while (!is_empty(s)) // 스택이 비어있지 않을 때까지
    {
        char lsn = pop(&s); // 스택 pop
        result = result * 10 + lsn; // 결과값에 추가
    }

    printf("%d", result);
    return 0;
}

int main(void)
{
    int num = 1222332;
    remove(num);

    return 0;
}
