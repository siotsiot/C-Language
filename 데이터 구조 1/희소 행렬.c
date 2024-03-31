#include <stdio.h>
sparse_matrix add_sparseMatrix(sparse_matrix, sparse_matrix); // 함수 원형 선언
void print(sparse_matrix, sparse_matrix, sparse_matrix);
#define MAX_SIZE 100 // 희소 행렬의 최대 요소 개수

// 희소 행렬의 요소 구조체 정의
typedef struct {
    int row;
    int col;
    int val;
} elt_ty;

// 희소 행렬 구조체 정의
typedef struct {
    elt_ty data[MAX_SIZE]; // 요소 배열
    int num;               // 요소의 개수
} sparse_matrix;

// 두 희소 행렬을 더하여 새로운 희소 행렬을 반환하는 함수
sparse_matrix add_sparseMatrix(sparse_matrix p, sparse_matrix q)
{
    sparse_matrix r;
    r.num = 0; // 결과 희소 행렬 r의 요소 개수 초기화

    // p와 q의 모든 요소를 탐색하면서 덧셈 수행
    int ip = 0, iq = 0; // ip는 행렬 p의 인덱스, iq는 행렬 q의 인덱스
    while (ip < p.num && iq < q.num)
    {
        // 행과 열이 동일한 경우
        if (p.data[ip].row == q.data[iq].row && p.data[ip].col == q.data[iq].col)
        {
            r.data[r.num].row = p.data[ip].row;
            r.data[r.num].col = p.data[ip].col;
            r.data[r.num].val = p.data[ip].val + q.data[iq].val;
            ip++;
            iq++;
        }
        // p의 요소가 더 작은 경우
        else if ((p.data[ip].row < q.data[iq].row) || (p.data[ip].row == q.data[iq].row && p.data[ip].col < q.data[iq].col))
        {
            r.data[r.num].row = p.data[ip].row;
            r.data[r.num].col = p.data[ip].col;
            r.data[r.num].val = p.data[ip].val;
            ip++;
        }
        // q의 요소가 더 작은 경우
        else
        {
            r.data[r.num].row = q.data[iq].row;
            r.data[r.num].col = q.data[iq].col;
            r.data[r.num].val = q.data[iq].val;
            iq++;
        }
        r.num++;
    }

    // p나 q의 요소가 남아있는 경우
    while (ip < p.num)
    {
        r.data[r.num].row = p.data[ip].row;
        r.data[r.num].col = p.data[ip].col;
        r.data[r.num].val = p.data[ip].val;
        r.num++;
        iq++;
    }
    while (iq < q.num)
    {
        r.data[r.num].row = q.data[iq].row;
        r.data[r.num].col = q.data[iq].col;
        r.data[r.num].val = q.data[iq].val;
        r.num++;
        iq++;
    }

    return r;
}

void print(sparse_matrix p, sparse_matrix q, sparse_matrix r) // 행렬 p, q, r을 출력하는 함수
{
    int i = 0;

    // 행렬 p 출력
    printf("- 희소 행렬 p -\n");
    for (i = 0; i < p.num; i++)
        printf("  (%d, %d, %d)\n", p.data[i].row, p.data[i].col, p.data[i].val);

    // 행렬 q 출력
    printf("\n- 희소 행렬 q -\n");
    for (int i = 0; i < q.num; i++)
        printf("  (%d, %d, %d)\n", q.data[i].row, q.data[i].col, q.data[i].val);

    // 행렬 r 출력
    printf("\n- 희소 행렬 r -\n");
    for (int i = 0; i < r.num; i++)
        printf("  (%d, %d, %d)\n", r.data[i].row, r.data[i].col, r.data[i].val);
}

int main()
{
    // 희소 행렬 p, q 초기화
    sparse_matrix p = { { {0, 2, 1}, {1, 5, 2}, {3, 1, 3}, {3, 9, 4}, {4, 0, 5}, {4, 4, 6}, {4, 9, 7} }, 7 };
    sparse_matrix q = { { {0, 0, 5}, {0, 4, 6}, {0, 9, 7}, {1, 1, 3}, {1, 5, 1}, {3, 5, 2}, {4, 4, 1}, {4, 9, 1} }, 8 };

    // 희소 행렬 p, q의 덧셈
    sparse_matrix r = add_sparseMatrix(p, q);

    // 희소 행렬 p, q, r 출력
    print(p, q, r);

    return 0;
}
