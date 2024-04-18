#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r;
	short c;
} element;

typedef struct {
	element stk[MAX_SIZE];
	int top;
} stack_type;

void init(stack_type* s)
{
	s->top = -1;
}

int is_empty(stack_type s)
{
	return (s.top == -1);
}

int is_full(stack_type s)
{
	return (s.top == (MAX_SIZE - 1));
}

void push(stack_type* s, element item)
{
	if (is_full(*s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else
		s->stk[++(s->top)] = item;
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
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s.stk[s.top];
}

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '1', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '1' },
	{ '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' },
};

void push_loc(stack_type* s, int r, int c) {
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r; tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++)
	{
		for (int c = 0; c < MAZE_SIZE; c++)
			printf("%c", maze[r][c]);
		printf("\n");
	}
}

int main(void)
{
	int r, c;
	stack_type s;

	init(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.'; // 현재 위치 방문 설정
		maze_print(maze);
		push_loc(&s, r - 1, c); // 막혀있지 않고 방문하지 않았으면 스택에 저장
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(s)) // 스택이 비어 있으면
		{
			printf("실패\n");
			return 0;
		}
		else // 스택에서 항목 꺼내와 현재 위치로 설정
			here = pop(&s);
	}
	printf("성공\n");
	return 0;
}
