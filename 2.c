#include <stdio.h>

int main()
{
	double a, b;
	printf("Podaj a: ");
	scanf("%lf", &a);
	printf("Podaj b: ");
	scanf("%lf", &b);
	printf("A+B = %.1lf", a+b);
	return 0;
}