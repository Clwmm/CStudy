#include <stdio.h>

double factorial(double i)
{
	if (i == 0 || i == 1)
		return 1;

	return i * (factorial(i - 1));
}

int main()
{
	double a;
	printf("Enter the number: ");
	scanf("%lf", &a);
	printf("Factorial from %.lf: %.lf\n", a, factorial(a));
	return 0;
}