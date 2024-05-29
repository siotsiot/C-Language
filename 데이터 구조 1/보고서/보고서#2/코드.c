#include <stdio.h>
#define MAX 100

// 희소 행렬 a의 각 원소를 나타내는 구조체
typedef struct {
    int row;
    int col;
    int val;
} elt_ty;

// 희소 행렬 a의 구조체 정의
typedef struct {
    elt_ty data[MAX]; // 요소 배열
    int num_elements;      // 요소의 개수
} SparseMatrix;

// 벡터 b 구조체 정의
typedef struct {
    int data[MAX]; // 벡터 요소 배열
    int size;           // 벡터의 크기
} Vector;

// 행렬과 벡터의 곱셈 함수
Vector matrix_vector_multi(SparseMatrix a, Vector b) {
    Vector c;
    int i;

    // 결과 벡터 c 초기화
    for (i = 0; i < MAX; i++)
        c.data[i] = 0;

    // 곱셈 수행
    for (i = 0; i < a.num_elements; i++)
        c.data[a.data[i].row] += a.data[i].val * b.data[a.data[i].col];

    // 결과 벡터의 크기 설정
    c.size = a.num_elements;

    return c;
}

// 결과 출력
void display(Vector c)
{
    printf("벡터 c: ");
    for (int i = 0; i < c.size; i++)
    {
        if (c.data[i] != 0) // 요소가 0이 아니면 출력
            printf("%d ", c.data[i]);
    }
}

int main()
{
    SparseMatrix a = { { { 0, 3, 7 }, { 1, 0, 9 }, { 1, 4, 8 }, { 2, 1, 1 }, { 3, 2, 3 }, { 3, 4, 5 } }, 6 }; // a 선언 및 초기화
    Vector b = { { 1, 2, 3, 4, 5, 6 }, 6 }; // b 선언 및 초기화
    Vector c; // c 선언

    c = matrix_vector_multi(a, b);
    display(c); // c를 출력한다.

    return 0;
}
