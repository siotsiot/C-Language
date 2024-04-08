#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

int main(void) {
    node* first, * p, * q;
    p = (node*)malloc(sizeof(node));
    p->val = 10;
    p->next = NULL;
    first = p;

    q = (node*)malloc(sizeof(node));
    q->val = 20;
    q->next = NULL;

    p->next = q;
    p = q;

    q = (node*)malloc(sizeof(node));
    q->val = 30;
    q->next = NULL;

    p->next = q;

    p = first;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }

    // 할당된 메모리 해제
    p = first;
    while (p != NULL) {
        node* temp = p->next;
        free(p);
        p = temp;
    }

    return 0;
}
