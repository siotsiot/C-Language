#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeType {
    int val;
    struct ListNodeType* link;
} ListNodeType;

ListNodeType* insert_first(ListNodeType* list, int item)
{
    ListNodeType* p = (ListNodeType*)malloc(sizeof(ListNodeType));
    p->val = item;
    p->link = list;
    return p;
}

ListNodeType* insert(ListNodeType* list, ListNodeType* prev, int item)
{
    ListNodeType* p = (ListNodeType*)malloc(sizeof(ListNodeType));
    p->val = item;
    if (prev == NULL)
    {
        p->link = list;
        list = p;
    }
    else
    {
        p->link = prev->link;
        prev->link = p;
    }
    return list;
}

ListNodeType* delete(ListNodeType* list, ListNodeType* prev)
{
    ListNodeType* p;

    if (list == NULL)
    {
        fprintf(stderr, "리스트가 비었습니다.\n");
        exit(1);
    }
    else if (prev == NULL)
    {
        p = list;
        list = p->link;
        free(p);
    }
    else
    {
        p = prev->link;
        prev->link = p->link;
        free(p);
    }
    return list;
}

ListNodeType* delete_first(ListNodeType* list)
{
    ListNodeType* p;

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

void print_list(ListNodeType* list)
{
    ListNodeType* p = list;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->link;
    }
    printf("\n");
}

int main(void)
{
    ListNodeType* list = NULL;
    list = insert_first(list, 10);
    list = insert_first(list, 20); // 리스트의 첫 번째 위치에 삽입
    list = insert_first(list, 30);
    list = insert_first(list, 40);
    list = insert(list, list, 50); // 리스트의 두 번째에 삽입

    list = delete_first(list); // 리스트의 첫 번째 항목 삭제
    list = delete(list, list); // 리스트의 두 번째 항목 삭제

    print_list(list); // 리스트에 포함된 모든 항목 출력

    return 0;
}
