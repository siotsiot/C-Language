#include <stdio.h>

int main(void)
{
    int x, y, z, result;
    
    printf("정수를 3개 입력하시오: ");
    scanf("%d %d %d", &x, &y, &z);
    
    result = x * y - z;
    
    printf("%d*%d-%d = %d\n", x, y, z, result);
    
    return 0;
}
