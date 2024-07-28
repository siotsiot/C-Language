#include <stdio.h>

int main(void)
{
    int distance, hour, min, sec;
    double time, velocity;
    
    printf("거리를 미터로 입력하시오: ");
    scanf("%d", &distance);
    printf("시간을 입력하시오: ");
    scanf("%d", &hour);
    printf("분을 입력하시오: ");
    scanf("%d", &min);
    printf("초를 입력하시오: ");
    scanf("%d", &sec);
    
    time = hour + (min / 60.0) + (sec / 360.0);
    velocity = (distance / 1000.0) / time;
    
    printf("속도: %lf\n", velocity);
    
    return 0;
}
