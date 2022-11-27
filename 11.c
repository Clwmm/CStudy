#include <stdio.h>

double silnia(double liczba);

int main()
{
	double n, k;
	printf("\nPodaj n: ");
	scanf("%lf", &n);
	printf("Podaj k: ");
	scanf("%lf", &k);

	if (k < 0 || n < 0 || n < k)
	{
		printf("Zla deklaracja zmiennych");
		return 0;
	}

	double dzielna = silnia(n);
	double dzielnik = silnia(k) * silnia(n - k);
	double wynik = dzielna / dzielnik;

	printf("Dwumian Newtwona wynosi: %lf\n\n", wynik);

	return 0;
};

double silnia(double liczba)
{
	if (liczba == 0 || liczba == 1)
		return 1;
	
	double wynik = 1.000000;

	for (double i = 2; i <= liczba; i++)
	{
		wynik *= i;
	}
	return wynik;
};