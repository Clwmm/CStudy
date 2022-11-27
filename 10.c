#include <stdio.h>

double silnia(double i)
{
	if (i == 0 || i == 1)
		return 1;

	return i * (silnia(i - 1));
}

int main()
{
	double a;
	printf("Podaj liczbe: ");
	scanf("%lf", &a);
	printf("Silnia z %.lf: %.lf", a, silnia(a));
	return 0;
}