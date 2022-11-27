#include <stdio.h>

int main()
{
	char operator;
	double pierwszy, drugi;
	printf("Wypisz dzialanie [liczby i operator oddzelone spacja]: \n");
	scanf("%lf %c %lf", &pierwszy, &operator, &drugi);
	switch (operator)
	{
	case '+':
		printf("Wynik: %lf", pierwszy + drugi);
		break;
	case '-':
		printf("Wynik: %.1lf", pierwszy - drugi);
		break;
	case '*':
		printf("Wynik: %.1lf", pierwszy * drugi);
		break;
	case '/':
		printf("Wynik: %.1lf", pierwszy / drugi);
		break;
	default:
		printf(" Podany zly operator");
		break;
	}

	return 0;
}