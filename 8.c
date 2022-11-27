#include <stdio.h>

unsigned NWD(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return b;
}

int main()
{
	int a, b;
	printf("Podaj dwie liczby [oddzielone spacja]: ");
	scanf("%d %d", &a, &b);
	printf("NWD: %d", NWD(a, b));
	return 0;
}