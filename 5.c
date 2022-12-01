#include <stdio.h>

int main()
{
	while (1)
	{
		char operator;
		double x, y;
		printf("[operator = q] End of program\n");
		printf("Write out the calculations [numbers and operator separated by space]:\n");
		scanf("%lf %c %lf", &x, &operator, &y);
		switch (operator)
		{
		case '+':
			printf("Result: %lf\n", x + y);
			break;
		case '-':
			printf("Result: %.1lf\n", x - y);
			break;
		case '*':
			printf("Result: %.1lf\n", x * y);
			break;
		case '/':
			printf("Result: %.1lf\n", x / y);
			break;
		case 'q':
			return 0;
		default:
			printf("Wrong operator specified\n");
			break;
		}
	}
	

	return 0;
}