#include <stdio.h>

int main()
{
	double A, B, x;
	printf("Specify A: ");
	scanf("%lf", &A);
	printf("Specify B: ");
	scanf("%lf", &B);
	printf("Specify x: ");
	scanf("%lf", &x);
	printf("y = %.1lf*%.1lf + %.1lf\n", A, x, B);
	printf("y = %.1lf\n", A * x + B);
	return 0;
}