#include <stdio.h>
double calculator(double x, double y);

int main(void)
{
    double zero = 0.0, one = 1.0, two = 2.0;
    
    printf("x=%lf, y=%lf, f(x,y)=%lf\n", one, two, calculator(one, two));
    printf("x=%lf, y=%lf, f(x,y)=%lf\n", two, zero, calculator(two, zero));
    printf("x=%lf, y=%lf, f(x,y)=%lf\n", two, one, calculator(two, one));

    return 0;
}

double calculator(double x, double y)
{
    double value;
    
    value = 1.5 * x + 3.0 * y;
    
    return value;
}
