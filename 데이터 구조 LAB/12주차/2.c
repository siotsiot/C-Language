#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node {
	element val;
	struct node* link;
} nodetype;

typedef struct {
	nodetype* rear;
} linked_circular_queue;

void init(linked_circular_queue* q)
{
	q->rear = NULL;
}

int is_empty(linked_circular_queue* q)
{
	return q->rear == NULL;
}

void enqueue(linked_circular_queue* q, element var)
{
	nodetype* new = (nodetype*)malloc(sizeof(nodetype));
	new->val = var;
	if (is_empty(q))
	{
		new->link = new;
		q->rear = new;
	}
	else
	{
		new->link = q->rear->link;
		q->rear->link = new;
		q->rear = new;
	}
}

element dequeue(linked_circular_queue* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "원형큐가 공백상태입니다.\n");
		exit(1);
	}
	nodetype* p = q->rear->link; // 삭제할 노드
	element value = p->val; // 삭제한 값을 반환하기 위해 저장
	// 자기자신을 가리키면 NULL로 설정
	if (q->rear == p)
		q->rear = NULL;
	// 그렇지 않으면 삭제할 노드가 가리킨 노드를 rear->link로 설정
	else
		q->rear->link = p->link;
	free(p);
	return value;
}

void print_queue(linked_circular_queue* q)
{
	if (is_empty(q))
	{
		printf("원형큐가 공백상태입니다.\n");
		return;
	}

	nodetype* p = q->rear->link;

	do {
		printf("%d ", p->val);
		p = p->link;
	} while (p != q->rear->link);
	printf("\n");
}

int main(void)
{
	linked_circular_queue q;
	
	init(&q);
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	print_queue(&q);
	
	dequeue(&q);
	print_queue(&q);
	
	enqueue(&q, 4);
	dequeue(&q);
	dequeue(&q);
	enqueue(&q, 5);
	print_queue(&q);

	return 0;
}
