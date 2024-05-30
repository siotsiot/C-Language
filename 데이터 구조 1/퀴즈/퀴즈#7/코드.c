#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node {
    element val;
    struct node* link;
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

nodetype* cons_list1()
{
    nodetype* list1 = NULL;
    int num = 3;

    for (int i = 1; i <= 10; i++)
        list1 = insert_last(list1, num * i);

    return list1;
}

nodetype* cons_list2()
{
    nodetype* list2 = NULL;
    int num = 5;

    for (int i = 0; i < 10; i++)
        list2 = insert_last(list2, num * i);

    return list2;
}

nodetype* merge(nodetype* list1, nodetype* list2)
{
    nodetype* head = NULL;
    nodetype* tail = NULL;

    // 헤드 포인트 결정
    if (list1->val <= list2->val)
    {
        head = tail = list1;
        list1 = list1->link;
    }
    else
    {
        head = tail = list2;
        list2 = list2->link;
    }

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val) // list1의 값이 작을 경우. 값이 같으면 list1의 값으로 설정.
        {
            tail->link = list1;
            tail = list1;
            list1 = list1->link;
        }
        else  // list2의 값이 작을 경우
        {
            tail->link = list2;
            tail = list2;
            list2 = list2->link;
        }
    }

    if (list1 != NULL)
        tail->link = list1;
    else
        tail->link = list2;

    return head;
}

void print_list(nodetype* list)
{
    while (list != NULL)
    {
        printf("%d ", list->val);
        list = list->link;
    }
    printf("\n");
}

int main(void)
{
    nodetype* list1 = cons_list1();
    nodetype* list2 = cons_list2();

    nodetype* merged_list = merge(list1, list2);
    print_list(merged_list);

    return 0;
}
