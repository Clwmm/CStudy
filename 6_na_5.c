﻿#include <stdio.h>
#define tab_max_size 7500

void factorial(int num);

int main()
{
	int number;
	printf("\nEnter a number [max 9000]: ");
	scanf("%d", &number);

	factorial(number);

	return 0;
};

void factorial(int num)
{
	if (num == 1 || num == 0)
	{
		printf("Factorial: 1");
		return;
	}

	int tab[tab_max_size];
	tab[0] = 1;
	for (int i = 1; i < tab_max_size; i++)
		tab[i] = 0;
	int tab_size = 1;

	for (int i = 0; i < num; i++)
	{

		for (int j = tab_size - 1; j >= 0; j--)
		{
			tab[j] *= (i + 1);

			if (tab[j] >= 100000)
			{
				int a = ((tab[j] % 1000000000) - (tab[j] % 100000));
				int b = a / 100000;
				tab[j] = tab[j] - a;
				tab[j + 1] += a / 100000;

				if (j == tab_size - 1)
				{
					tab_size++;
					if (tab_size > 6337)
					{
						printf("Out of range");
						return;
					}
				}
			}
		}
		if (tab_size > tab_max_size)
			break;
	}

	printf("\nFactorial of %d:\n", num);
	for (int i = tab_size - 1; i >= 0; i--)
	{
		if (tab[i] == 0)
			printf("00000");
		else
			printf("%d", tab[i]);
	}
	printf("\n\n");
}

// https://coolconversion.com/math/factorial/


/*
	int a = 432573829;

	"Jednosci: " -- a % 10                                             -- 9
	"Dziesiatki: " -- ((a % 100) - (a % 10)) / 10                      -- 2
	"Setki: " -- ((a % 1000) - (a % 100)) / 100                        -- 8
	"Tysiace: " -- ((a % 10000) - (a % 1000)) / 1000                   -- 3
	"10tys: " -- ((a % 100000) - (a % 10000)) / 10000                  -- 7
	"100tys(i więcej): " -- ((a % 1000000000) - (a % 100000)) / 100000 -- 4325

	int b = ((a % 1000000000) - (a % 100000)) / 100000;
	int c = a - ((a % 1000000000) - (a % 100000));
*/

/*
char 1B [−128; 127]

int co najmniej 2B [−32768; 32767]
	często 4B [−2147483648; 2147483647]

short int nie więcej niż int
	często 2B [−32768; 32767]

long int nie mniej niż int
	często 8 B [−9223372036854775808; 9223372036854775807]
*/