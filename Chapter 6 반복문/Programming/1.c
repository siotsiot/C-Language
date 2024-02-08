#include <stdio.h>

int main(void)
{
    int sec;
    
    for (sec = 60; sec > 0; sec--)
        printf("%d ", sec);
    
    printf("발사\n");
    
    return 0;
}
