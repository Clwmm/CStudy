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
	printf("Enter two numbers [separated by a space]: ");
	scanf("%d %d", &a, &b);
	printf("NWD: %d\n", NWD(a, b));
	return 0;
}