#include <stdio.h>

int main(void)
{
    int i, j, a, b;
    int A[9][9] = { 0 };
    
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            A[i][j] = (i + 1) * (j + 1);
        }
    }
    
    printf("알고 싶은 구구단을 입력하시오(예: 9 3): ");
    scanf("%d %d", &a, &b);
    printf("%dX%d=%d\n", a, b, A[a - 1][b - 1]);
    
    return 0;
}
