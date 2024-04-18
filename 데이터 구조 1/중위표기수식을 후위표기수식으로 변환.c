#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

// 스택의 타입 정의
typedef char element;

// 스택 요소 정의
typedef struct {
	char stk[MAX_SIZE];
	int top;
} stack_type;

// 스택 초기화
void init(stack_type* s)
{
	s->top = -1;
}

// 스택 공백 여부
element is_empty(stack_type s)
{
	return (s.top == -1); // 안 비어있으면 0, 비어있으면 1
}

// 스택 포화 여부
element is_full(stack_type s)
{
	return (s.top == (MAX_SIZE - 1)); // 스택에 공간이 있으면 0, 가득 있으면 1
}

// 삽입 연산(push)
void push(stack_type* s, element ch)
{
	if (is_full(*s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->stk[++(s->top)] = ch;
}

// 삭제 연산(pop)
element pop(stack_type* s)
{
	if (is_empty(*s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->stk[(s->top)--];
}

// 스택의 top의 값 조회
element peek(stack_type s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else
		return s.stk[s.top];
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
			return 2;
		case '(':
			return 3;
	}
	return -1;
}

void postfix(char exp[])
{
	stack_type s;
	init(&s);
	int i = 0;
	char ch, top_op;

	while ((ch = exp[i++]) != '\0')
	{
		if (isdigit(ch)) // 숫자면 출력
			printf("%c", ch);
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			while (!is_empty(s) && PIS(peek(s)) >= PIE(ch))
				printf("%c", pop(&s));
			push(&s, ch);
		}
		else if (ch == '(')
			push(&s, ch);
		else if (ch == ')')
		{
			top_op = pop(&s);
			while (!is_empty(s) && top_op != '(')
			{
				printf("%c", top_op);
				top_op = pop(&s);
			}
		}
	}
	
	while (!is_empty(s))
		printf("%c", pop(&s));
}

int main(void)
{
	char exp[] = "2+3*4"; // 중위 표기식 작성
	printf("중위 표기식: %s\n", exp);
	printf("후위 표기식: ");
	postfix(exp);

	return 0;
}
