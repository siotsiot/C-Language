#include <stdio.h>
#define PI 3.14 // 기호상수 정의

int main(void)
{
    double radius, area, volume;
    
    printf("반지름을 입력하시오: ");
    scanf("%lf", &radius);
    
    area = 4.0 * PI * (radius * radius);
    volume = 4.0 / 3.0 * PI * (radius * radius * radius);
    
    printf("구의 표면적: %lf\n", area);
    printf("구의 부피: %lf\n", volume);
    
    return 0;
}
