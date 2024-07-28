#include <stdio.h>

int main(void)
{
    int i, max, min;
    int a[5] = { 0 };
    
    for (i = 0; i < 5; i++)
    {
        printf("정수를 입력하시오: ");
        scanf("%d", &a[i]);
        min = max = a[0];
        
        if (max < a[i])
            max = a[i];
        else if (min > a[i])
            min = a[i];
    }
    
    printf("최댓값=%d 최솟값=%d\n", max, min);
    
    return 0;
}
