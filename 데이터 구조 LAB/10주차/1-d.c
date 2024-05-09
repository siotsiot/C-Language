#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_SIZE];
    int front, rear;
} dq_Type;

// 초기화
void init_deque(dq_Type* q)
{
    q->front = 0;
    q->rear = 0;
}

// 공백 상태 확인
int is_empty(dq_Type*q)
{
    return (q->front == q->rear);
}

// 포화 상태 확인
int is_full(dq_Type*q)
{
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// rear 삽입 함수
void add_rear(dq_Type* q, element item)
{
    if (!is_full(q))
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = item;
    }
    else
    {
        fprintf(stderr, "덱큐가 포화 상태입니다.\n");
        exit(1);
    }
}

// front 삭제 함수
element delete_front(dq_Type* q)
{
    if (!is_empty(q))
        return q->data[(++q->front) % MAX_SIZE];
    else
    {
        fprintf(stderr, "덱큐가 공백 상태입니다.\n");
        exit(1);
    }
}

// front 삽입 함수
void add_front(dq_Type* q, element val)
{
    if (!is_full(q))
    {
        q->data[q->front] = val;
        q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    else
    {
        fprintf(stderr, "덱큐가 포화 상태입니다.\n");
        exit(1);
    }
}

// rear 삭제 함수
element delete_rear(dq_Type* q)
{
    if (!is_empty(q))
    {
        int prev = q->rear;
        q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
        return q->data[prev];
    }
    else
    {
        fprintf(stderr, "덱큐가 공백 상태입니다.\n");
        exit(1);
    }
}

element get_rear(dq_Type* q)
{
    if (!is_empty(q))
        return q->data[q->rear];
    else
    {
        fprintf(stderr, "덱큐가 공백 상태입니다.\n");
        exit(1);
    }
}

element get_front(dq_Type* q)
{
    if (!is_empty(q))
        return q->data[(q->front + 1) % MAX_SIZE];
    else
    {
        fprintf(stderr, "덱큐가 공백 상태입니다.\n");
        exit(1);
    }
}

void print_deque(dq_Type* q)
{
    printf("rear = %d front = %d | ", q->rear, q->front);
    if (!is_empty(q))
    {
        int i = q->front;
        do {
            i = (i + 1) % MAX_SIZE;
            printf("%d ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
        printf("\n");
    }
    else
        printf("덱큐가 비어 있습니다.\n");
}

int main(void)
{
    dq_Type q;
    init_deque(&q);

    add_rear(&q, 1);
    add_rear(&q, 2);
    add_front(&q, 3);
    add_front(&q, 4);
    delete_rear(&q);
    delete_front(&q);
    add_front(&q, 5);
    print_deque(&q);
    
    return 0;
}
