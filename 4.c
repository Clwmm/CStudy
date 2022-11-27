#include <stdio.h>

int main()
{
	double A, B, C, x;
	printf("Podaj A: ");
	scanf("%lf", &A);
	printf("Podaj B: ");
	scanf("%lf", &B);
	printf("Podaj C: ");
	scanf("%lf", &C);
	printf("Podaj x: ");
	scanf("%lf", &x);
	printf("y = %.1lf*%.1lf*%.1lf + %.1lf*%.1lf + %.1lf", A, x, x, B, x, C);
	printf("\ny = %.1lf", A*x*x + B*x + C);
	return 0;
}