#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, num, max, order;
    int a[10] = { 0 };
    
    srand(time(NULL));
    
    for (i = 0; i < 100; i++)
    {
        num = rand() % 10;
        a[num]++;
    }
    
    for (i = 0; i < 10; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    
    max = a[0]; // 배열의 첫번째 값으로 초기화
    
    for (i = 0; i < 10; i++)
    {
        if (max <= a[i])
        {
            max = a[i];
            order = i;
        }
    }
    
    printf("가장 많이 생선된 수=%d\n", order);
    
    return 0;
}
