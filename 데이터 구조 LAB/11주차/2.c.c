#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype {
    int val;
    struct nodetype* link;
} nodetype;

nodetype* insert_last(nodetype* list, int val)
{
    nodetype* p = (nodetype*)malloc(sizeof(nodetype));
    p->val = val;
    p->link = NULL;

    if (list == NULL)
        return p;

    nodetype* temp = list;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = p;
    return list;
}

nodetype* cons_list(nodetype* list)
{
    list = insert_last(list, 5);
    list = insert_last(list, 6);
    list = insert_last(list, 7);
    
    return list;
}

nodetype* delete_first(nodetype* list)
{
    nodetype* p;

    if (list == NULL)
    {
        fprintf(stderr, "리스트가 비었습니다.\n");
        exit(1);
    }
    else
    {
        p = list;
        list = p->link;
        free(p);
    }
    return list;
}

nodetype* delete_last(nodetype* list)
{
    if (list == NULL)
    {
        fprintf(stderr, "리스트가 비었습니다.\n");
        exit(1);
    }
    else
    {
        nodetype* temp = list;
        while (temp->link->link != NULL)
            temp = temp->link;
        free(temp->link);
        temp->link = NULL;
        return list;
    }
}

void print_list(nodetype* list)
{
    nodetype* p = list;

    while (p != NULL)
    {
        printf("%d", p->val);
        if (p->link != NULL)
            printf(">");
        p = p->link;
    }
    printf("\n");
}

int main(void)
{
    nodetype* head = NULL;
    head = cons_list(head);
    printf("After list construction using last insertion\n");
    print_list(head);
    printf("\nAfter deletion using last deletion\n");
    head = delete_last(head);
    print_list(head);

    return 0;
}
