#include <stdio.h>

unsigned fibonacci(int n);

int main()
{
	int n;
	printf("Give the number of the Fibonacci sequence: ");
	scanf("%d", &n);
	printf("%d The number of the Fibonacci sequence is: %d", n, fibonacci(n));
	return 0;
}

unsigned fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		unsigned l = 0, p = 1;
		unsigned wynik;

		for (int i = 2; i <= n; i++)
		{
			wynik = l + p;
			l = p;
			p = wynik;
		}

		return wynik;
	}
}