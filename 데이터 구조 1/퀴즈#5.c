#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef char element;
typedef struct {
    element data[MAX_SIZE];
    int front, rear;
} DequeType;

// 초기화
void init_deque(DequeType* q)
{
    q->front = 0;
    q->rear = 0;
}

// 공백 상태 확인
int is_empty(DequeType q)
{
    return (q.front == q.rear);
}

// 포화 상태 확인
int is_full(DequeType q)
{
    return ((q.rear + 1) % MAX_SIZE == q.front);
}

// rear 삽입 함수
void add_rear(DequeType* q, element item)
{
    if (!is_full(*q))
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
element delete_front(DequeType* q)
{
    if (!is_empty(*q))
        return q->data[(++q->front) % MAX_SIZE];
    else
    {
        fprintf(stderr, "덱큐가 공백 상태입니다.\n");
        exit(1);
    }
}

// front 삽입 함수
void add_front(DequeType* q, element val)
{
    if (!is_full(*q))
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
element delete_rear(DequeType* q)
{
    if (!is_empty(*q))
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

element get_rear(DequeType* q)
{
    if (!is_empty(*q))
        return q->data[q->rear];
    else
    {
        fprintf(stderr, "덱큐가 공백 상태입니다.\n");
        exit(1);
    }
}

element get_front(DequeType* q)
{
    if (!is_empty(*q))
        return q->data[(q->front + 1) % MAX_SIZE];
    else
    {
        fprintf(stderr, "덱큐가 공백 상태입니다.\n");
        exit(1);
    }
}

void deque_print(DequeType* q)
{
    printf("front = %d rear = %d | ", q->front, q->rear);
    if (!is_empty(*q))
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

int is_palin(DequeType* q, char s[])
{
    int i = 0;
    int len = strlen(s);
    char ch;

    while ((ch = s[i++]) != '\0')
        add_rear(q, ch);

    while (!is_empty(*q))
    {
        if (len == 1) // 한 자리만 남으면 
            return 1;
        char ch1 = delete_front(q);
        len--;
        char ch2 = delete_rear(q);
        len--;
        
        if (ch1 != ch2)
            return 0;
    }
    return 1;
}

int main(void)
{
    DequeType q;
    int menu = 0;
    do {
        printf("1. 회문 확인\n");
        printf("2. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &menu);
        //getchar(); // 버퍼 제거

        switch (menu)
        {
            case 1:
                init_deque(&q);
                char s[MAX_SIZE];

                printf("\n문자열을 입력하세요: ");
                scanf("%s", s);

                int res = is_palin(&q, s);

                if (res)
                    printf("s is Palindrome.\n\n");
                else
                    printf("s is NOT Palindrome.\n\n");
                break;

            case 2:
                printf("\n프로그램이 종료되었습니다.\n");
                break;

            default:
                printf("잘못 입력했습니다. 다시 입력하세요.\n\n");
                break;
        }
    } while (menu != 2);
    
    return 0;
}
