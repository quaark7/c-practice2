#include <stdio.h>
#include <math.h>

int main(){
    
    double alpha, beta;

    printf("Enter alpha: ");
    scanf("%lf", &alpha);

    printf("Enter beta: ");
    scanf("%lf", &beta);

    double z1 = pow((cos(alpha) - cos(beta)), 2) - pow((sin(alpha) - sin(beta)), 2);
    double z2 = -4.0 * pow(sin((alpha - beta) / 2.0), 2) * cos(alpha + beta);

    printf("z1 = %lf\n", z1);
    printf("z2 = %lf\n", z2);

    return 0;
}