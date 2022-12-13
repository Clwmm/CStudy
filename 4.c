#include <stdio.h>

int main()
{
	double A, B, C, x;
	printf("Specify A: ");
	scanf("%lf", &A);
	printf("Specify B: ");
	scanf("%lf", &B);
	printf("Specify C: ");
	scanf("%lf", &C);
	printf("Specify x: ");
	scanf("%lf", &x);
	printf("y = %.1lf*%.1lf*%.1lf + %.1lf*%.1lf + %.1lf\n", A, x, x, B, x, C);
	printf("y = %.1lf\n", A*x*x + B*x + C);
	return 0;
}