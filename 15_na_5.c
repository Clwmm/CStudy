#include <stdio.h>

typedef enum { F, T } boolean;

void print_zeros(int mn, int system)
{
	int iter = mn;
	iter /= system;
	while (iter > 0)
	{
		printf("0");
		iter /= system;
	}
}

void print_num(int num)
{
	if (num >= 0 && num <= 9)
	{
		printf("%d", num);
		return;
	}

	switch (num)
	{
	case 10:
		printf("A");
		break;
	case 11:
		printf("B");
		break;
	case 12:
		printf("C");
		break;
	case 13:
		printf("D");
		break;
	case 14:
		printf("E");
		break;
	case 15:
		printf("F");
		break;
	case 16:
		printf("G");
		break;
	case 17:
		printf("H");
		break;
	case 18:
		printf("I");
		break;
	case 19:
		printf("J");
		break;
	default:
		break;
	}

}

void converter(int number, int system)
{
	if (number <= 0)
	{
		printf("\n0\n");
		return;
	}

	printf("Liczba w systemie %d : ", system);

	int num = number;
	int iterator = 0;
	int mn = 1;

	boolean init = T;
	boolean sc_init = T;

	while (num > 0)
	{
		while (init == T)
		{
			if (num > mn)
				mn *= system;
			else if (num == mn)
				init = F;
			else
			{
				mn /= system;
				init = F;
			}
		}
		
		int temp_num = mn;
		while (sc_init == T)
		{
			if (num == temp_num)
			{
				print_num(temp_num / mn);
				print_zeros(mn, system);
				return;
			}
			else if (num > temp_num)
			{
				temp_num += mn;
			}
			else
			{
				temp_num -= mn;
				print_num(temp_num / mn);
				num -= temp_num;
				mn /= system;
				sc_init = F;
			}
		}
		sc_init = T;
	}
}

int main()
{
	int number, system;

	printf("Give the integer in decimal system: ");
	scanf("%d", &number);
	printf("Specify which system to convert to [from 2 to 20]: ");
	scanf("%d", &system);
	
	converter(number, system);
	
	return 0;
};