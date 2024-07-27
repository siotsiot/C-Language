#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, j, direction;
    char tile[10] = { '_', '_', '_', '_', '_', '_', '_', '_', '_', '_' };
    
    srand(time(NULL));
    
    int bug = 5;
    tile[bug] = '*';
    
    for (i = 0; i < 10; i++) // 처음 상태 출력.
    {
        printf("%c ", tile[i]);
    }
    printf("\n");
    
    for (i = 0; i < 100; i++) // 횟수 반복.
    {
        direction = rand() % 2;
        if (direction == 0) // 왼쪽으로 가기.
        {
            if (bug - 1 > 0)
            {
                tile[bug - 1] = '*';
                tile[bug] = '_';
                bug -= 1;
            }
        }
        else // 오른쪽으로 가기.
        {
            if (bug + 1 < 10)
            {
                tile[bug + 1] = '*';
                tile[bug] = '_';
                bug += 1;
            }
        }
        for (j = 0; j < 10; j++) // 지나간 길 출력.
        {
            printf("%c ", tile[j]);
        }
        printf("\n");
    }
    
    return 0;
}
