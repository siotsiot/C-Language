#include <stdio.h>

int main(void)
{
    int row, col, i, j;
    int a[100][100] = { 0 };
    int b[100][100] = { 0 };
    
    printf("행 개수=");
    scanf("%d", &row);
    printf("열 개수=");
    scanf("%d", &col);
    
    printf("행렬 입력=\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            scanf("%d", &a[i][j]);
    }
    
    for (i = 0; i < row; i++)
    {
        for (j = 0 ; j < col; j++)
        {
            b[j][i] = a[i][j];
        }
    }
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    
    return 0;
}
