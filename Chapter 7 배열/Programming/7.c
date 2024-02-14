#include <stdio.h>

int main(void)
{
    int row, col, i, j, k;
    int a[100][100] = { 0 };
    int b[100][100] = { 0 };
    int c[100][100] = { 0 };
    
    printf("행 개수=");
    scanf("%d", &row);
    printf("열 개수=");
    scanf("%d", &col);
    
    printf("첫 번째 행렬 입력=\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            scanf("%d", &a[i][j]);
    }
    
    printf("두 번째 행렬 입력=\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            scanf("%d", &b[i][j]);
    }
    
    for (i = 0; i < row; i++)
    {
        for (j = 0 ; j < col; j++)
        {
            for (k = 0; k < col; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    
    return 0;
}
