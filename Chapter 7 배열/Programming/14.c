#include <stdio.h>
#include <math.h>
#define N 5

int main(void)
{
    int i;
    double m_sum = 0.0, v_sum = 0, m, v;
    double a[] = { 0 };
    
    for (i = 0; i < N; i++)
    {
        printf("실수를 입력하시오: ");
        scanf("%lf", &a[i]);
    }
    
    for (i = 0; i < N; i++)
    {
        m_sum += a[i];
    }
    m = m_sum / N;
    
    for (i = 0; i < N; i++)
    {
        v_sum += pow((a[i] - m), 2);
    }
    v = v_sum / N;
    
    printf("평균: %lf\n", m);
    printf("표준편차: %lf\n", sqrt(v));
    
    return 0;
}
