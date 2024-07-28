#include <stdio.h>

int main(void)
{
    int a[10] = { 0 };
    int sit, i;
    char book;
    
    while(1)
    {
        printf("좌석을 예약하시겠습니까?(y 또는 n) ");
        getchar(); // 버퍼 \n을 잡기 위해 작성함.
        scanf("%c", &book);
        if (book == 'n')
            break;
        
        
        printf("몇 번째 좌석을 예약하시겠습니까? ");
        scanf("%d", &sit);
        
        a[sit - 1] = 1;
        
        printf("---------------------------------\n");
        printf("  1  2  3  4  5  6  7  8  9  10\n");
        printf("---------------------------------\n");
        for (i = 0; i < 10; i++)
            printf("  %d", a[i]);
        printf("\n");
    }
    
    return 0;
}
