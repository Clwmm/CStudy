#include <stdio.h>

int main()
{
	double A, B, x;
	printf("Podaj A: ");
	scanf("%lf", &A);
	printf("Podaj B: ");
	scanf("%lf", &B);
	printf("Podaj x: ");
	scanf("%lf", &x);
	printf("y = %.1lf*%.1lf + %.1lf", A, x, B);
	printf("\ny = %.1lf", A * x + B);
	return 0;
}