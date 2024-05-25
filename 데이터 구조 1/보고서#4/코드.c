#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct { // 항 표현
    int coef;
    int expo;
} term_type;

typedef struct { // 다항식 표현
    term_type terms[MAX_TERMS]; // 항의 배열
    int nums; // 항의 개수
} poly;

typedef struct node { // 다항식의 한 항을 표현하는 타입 nodetype 정의
    term_type term; // 항의 정보(계수, 차수)
    struct node* link; // 다음 노드를 가리키는 링크
} nodetype;

void init(poly* p) // 항 초기화
{
    p->nums = 0;
}

// 리스트 노드 생성
nodetype* insert_last(nodetype* list, term_type new)
{
    nodetype* new_node = (nodetype*)malloc(sizeof(nodetype)); // 새 노드 생성

    new_node->term = new;
    new_node->link = NULL;

    if (list == NULL) // list가 NULL이면 노드가 없으므로 그대로 반환
        return new_node;
    
    nodetype* temp = list;
    while (temp->link != NULL) // 마지막 노드까지 가기
        temp = temp->link;

    temp->link = new_node; // 마지막 노드의 link를 새 노드에 가리키게 함

    return list;
}

// 배열로 표현된 다항식을 연결 리스트로 변경
nodetype* poly_array2list(poly p)
{
    nodetype* list = NULL; // 리스트 생성
    for (int i = 0; i < p.nums; i++)
        list = insert_last(list, p.terms[i]);
    
    return list;
}

// 두 개의 다항식 합
nodetype* add_poly_list(nodetype* list1, nodetype* list2)
{
    nodetype* sum = NULL; // 더한 결과
    nodetype* p1 = list1;
    nodetype* p2 = list2;

    while (p1 != NULL && p2 != NULL) // 두 다항식의 link가 NULL이 아닐 때까지 반복
    {
        if (p1->term.expo > p2->term.expo) // p1의 차수가 클 때
        {
            sum = insert_last(sum, p1->term);
            p1 = p1->link;
        }
        else if (p1->term.expo < p2->term.expo) // p2의 차수가 클 때
        {
            sum = insert_last(sum, p2->term);
            p2 = p2->link;
        }
        else // p1과 p2의 차수가 같을 때
        {
            term_type sum_term;
            sum_term.coef = p1->term.coef + p2->term.coef;
            sum_term.expo = p1->term.expo;
            sum = insert_last(sum, sum_term);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while (p1 != NULL) // p1의 항이 남았을 때
    {
        sum = insert_last(sum, p1->term);
        p1 = p1->link;
    }

    while (p2 != NULL) // p2의 항이 남았을 때
    {
        sum = insert_last(sum, p2->term);
        p2 = p2->link;
    }

    return sum;
}

// 더한 다항식 출력
void print_poly(nodetype* list)
{
    nodetype* p = list;
    while (p != NULL)
    {
        if (p != list && p->term.coef > 0) // 현재 노드의 값과 다르고, 계수가 0보다 크면
            printf(" + "); // '+'기호 출력
        else if (p->term.coef < 0) // 계수가 음수면
            printf(" - "); // '-'기호 출력

        if (p->term.coef != 0) // 계수가 0이 아니면
            printf("%d", abs(p->term.coef)); // 계수의 절댓값 출력 (∵ 109 ~ 110 line에서 이미 '-'기호를 출력)

        if (p->term.expo > 0 && p->term.coef != 0) // 차수가 0보다 크고, 계수가 0이 아니라면
        {
            printf("x"); // 'x'기호 출력
            if (p->term.expo != 1) // 차수가 1이 아니면
                printf("^%d", p->term.expo); // '^'기호와 차수 출력
        }

        p = p->link;
    }
    printf("\n");
}

// 다항식을 이루는 연결 리스트의 동적 메모리 해제
void free_poly(nodetype* list)
{
    nodetype* temp;

    while (list != NULL)
    {
        temp = list;
        list = list->link;
        free(temp);
    }
}

int main(void)
{
    poly poly1 = { {{10, 5}, {5, 2}, {6, 1}, {1, 0}}, 4 }; // 10x^5 + 5x^2 + 6x + 1
    poly poly2 = { {{7, 3}, {3, 2}, {-6, 1}}, 3 };         // 7x^3 + 3x^2 - 6x

    // 리스트로 표현된 다항식을 생성
    nodetype* list1 = poly_array2list(poly1);
    nodetype* list2 = poly_array2list(poly2);

    // 다항식 덧셈
    nodetype* list3 = add_poly_list(list1, list2);

    // 다항식 출력
    printf("다항식 1: ");
    print_poly(list1);
    printf("다항식 2: ");
    print_poly(list2);
    printf("다항식 합: ");
    print_poly(list3);

    // 다항식 해제
    free_poly(list1);
    free_poly(list2);
    free_poly(list3);

    return 0;
}
