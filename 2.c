#include <stdio.h>

int main()
{
	double a, b;
	printf("Specify a: ");
	scanf("%lf", &a);
	printf("Specify b: ");
	scanf("%lf", &b);
	printf("A+B = %.1lf\n", a+b);
	return 0;
}