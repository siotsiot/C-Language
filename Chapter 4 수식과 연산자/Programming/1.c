#include <stdio.h>

int main(void)
{
    float weight, height, bmi;
    
    printf("체중을 입력하시오: ");
    scanf("%f", &weight);
    printf("신장을 입력하시오(단위: 미터): ");
    scanf("%f", &height);
    
    bmi = weight / (height * height);
    
    printf("BMI: %f\n", bmi);
    
    
    return 0;
}
