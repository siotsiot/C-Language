#include <stdio.h>
#include <math.h>
void quad_eqn(int, int, int);

int main(void)
{
    int a, b, c;
    printf("2차 방저익의 계수를 입력하시오:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    
    quad_eqn(a, b, c);
    
    return 0;
}

void quad_eqn(int a, int b, int c)
{
    double x1, x2; // x1과 x2는 서로 다른 실근.
    if (pow(b, 2) - 4 * a * c > 0)
    {
        x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        printf("첫 번째 근=%lf\n", x1);
        printf("두 번째 근=%lf\n", x2);
    }
    else
        printf("근이 없습니다.\n");
}
