#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

typedef double element;
typedef struct {
	char stk[MAX_SIZE];
	int top;
} stack_type;

void init(stack_type* s)
{
	s->top = -1;
}

element is_empty(stack_type s)
{
	return (s.top == -1); // 안 비어있으면 0, 비어있으면 1
}

element is_full(stack_type s)
{
	return (s.top == (MAX_SIZE - 1)); // 스택에 공간이 있으면 0, 가득 있으면 1
}

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

double compute(char op, double x, double y)
{
	switch (op)
	{
		case '+':
			return x + y;
			break;

		case '-':
			return x - y;
			break;

		case '*':
			return x * y;
			break;

		case '/':
			return x / y;
			break;

		default:
			printf("유효하지 않은 연산자입니다.\n");
			return 0;
			break;
	}
}

double eval(char exp[])
{
	stack_type s;
	init(&s);
	int ip = 0;
	double op1, op2, result = 0;
	char ch;

	while ((ch = exp[ip++]) != '\0')
	{
		if (isdigit(ch)) // 숫자면 push. isdigit는 숫자가 아니면 0, 숫자면 1
			push(&s, ch - '0'); // ch의 아스키 코드값이 들어가므로 문자열 0을 빼줌으로써 본래 값이 들어감
			
		else // 숫자가 아니면 pop
		{
			op2 = pop(&s);
			op1 = pop(&s);
			result = compute(ch, op1, op2);
			push(&s, result);
		}
	}
	return pop(&s);
}

int main(void)
{
	char exp[] = "52*34-25*++";

	printf("%s = %lf\n", exp, eval(exp));

	return 0;
}
