#include <stdio.h>

double factorial(double number);

int main()
{
	double n, k;
	printf("\Specify n: ");
	scanf("%lf", &n);
	printf("Specify k: ");
	scanf("%lf", &k);

	if (k < 0 || n < 0 || n < k)
	{
		printf("Wrong declaration of variables");
		return 0;
	}

	double x = factorial(n);
	double y = factorial(k) * factorial(n - k);
	double result = x / y;

	printf("Newtwon's binomial is: %lf\n\n", result);

	return 0;
};

double factorial(double number)
{
	if (number == 0 || number == 1)
		return 1;
	
	double result = 1.000000;

	for (double i = 2; i <= number; i++)
	{
		result *= i;
	}
	return result;
};