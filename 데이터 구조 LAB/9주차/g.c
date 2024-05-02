#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
typedef struct
{
    int data[MAX_SIZE];
    int rear, front;
} QueueType;

void init(QueueType* q)
{
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType q)
{
    return (q.rear == (MAX_SIZE - 1));
}

int is_full(QueueType q)
{
    return (((q.rear + 1) % MAX_SIZE) == q.front);
}

void enqueue(QueueType* q, element element)
{
    if (!is_full(*q))
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = element;
    }
    else
    {
        fprintf(stderr, "큐가 가득 찼습니다.\n");
        exit(1);
    }
}

element dequeue(QueueType* q)
{
    if (!is_empty(*q))
    {
        q->front = (q->front + 1) % MAX_SIZE;
        return q->data[q->front];
    }
    else
    {
        fprintf(stderr, "큐가 비어 있습니다.\n");
        exit(1);
    }
}

void queue_print(QueueType* q)
{
    if (!is_empty(*q))
    {
        int i = q->front;
        do {
            i = (i + 1) % MAX_SIZE;
            printf("%d ", q->data[i]);

        } while (i != q->rear);
        printf("\n");
    }
    else
    {
        fprintf(stderr, "큐가 비어 있습니다.\n");
        exit(1);
    }
}

int main(void)
{
    QueueType q;
    init(&q);

    printf("enqueue(&q, 1);\n");
    enqueue(&q, 1);
    queue_print(&q);

    printf("\nenqueue(&q, 2);\n");
    enqueue(&q, 2);
    queue_print(&q);

    printf("\ndequeue(&q);\n");
    dequeue(&q);
    queue_print(&q);

    printf("\nenqueue(&q, 3);\n");
    enqueue(&q, 3);
    queue_print(&q);

    printf("\nenqueue(&q, 4);\n");
    enqueue(&q, 4);
    queue_print(&q);

    printf("\ndequeue(&q);\n");
    dequeue(&q);
    queue_print(&q);

    printf("\nenqueue(&q, 5);\n");
    enqueue(&q, 5);
    queue_print(&q);

    printf("\nenqueue(&q, 6);\n");
    enqueue(&q, 6);
    queue_print(&q);

    return 0;
}
