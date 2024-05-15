#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType {
    int val;
    struct nodeType* next;
} nodeType;

int main(void)
{
    nodeType* first;
    first = (nodeType*)malloc(sizeof(nodeType));
    first->val = 10;

    first->next = (nodeType*)malloc(sizeof(nodeType));
    first->next->val = 20;

    first->next->next = (nodeType*)malloc(sizeof(nodeType));
    first->next->next->val = 30;
    first->next->next->next = NULL;

    nodeType* current = first; // current가 처음 노드를 가리킴.
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }

    current = first; // 다시 처음 노드를 가리킴.
    while (current != NULL)
    {
        nodeType* temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}
