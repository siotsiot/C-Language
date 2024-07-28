#include <stdio.h>

int main(void)
{
    float kor, eng, math;
    
    printf("3과목의 점수를 입력한다: ");
    scanf("%f %f %f", &kor, &eng, &math);

    printf("총점=%.2f\n", kor + eng + math);
    printf("평균=%.2f\n", (kor + eng + math) / 3.0);
    return 0;
}
