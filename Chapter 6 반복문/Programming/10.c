#include <stdio.h>

int main(void)
{
    double f, c;
    
    printf("===========================\n");
    printf("화씨온도                섭씨온도\n");
    printf("===========================\n");
    
    for (f = 0; f <= 100; f += 10)
    {
        c = (f - 32.0) * (5.0 / 9.0);
        printf("%d                     %d\n", (int)f, (int)c);
    }
    
    return 0;
}
