#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "18_calc.h"

#define MAX_LINE 1000

int main(int argc, char* argv[])
{
	char in[MAX_LINE];
	char* pch;
	
	char* function[MAX_LINE];
	int c_fun = 0;
	
	printf("Enter a function: ");

	fgets(in, MAX_LINE, stdin);
	pch = strtok(in, " ");
	while (pch != NULL)
	{
		function[c_fun] = malloc(strlen(pch) + 1);
		strcpy(function[c_fun], pch);
		c_fun++;
		pch = strtok(NULL, " ");
	}

	double x_start, x_end, delta_x, n, integral = 0;

	printf("Enter x_start: ");
	scanf("%lf", &x_start);
	printf("Enter x_end: ");
	scanf("%lf", &x_end);
	printf("Enter delta_x: ");
	scanf("%lf", &delta_x);


	n = (x_end - x_start) / delta_x;

	clock_t t;
	t = clock();

	for (int i = 0; i < n; i++)
	{
		integral += calc(function, c_fun, x_start + (i * delta_x));
	}
	integral += calc(function, c_fun, x_start) * 0.5;
	integral += calc(function, c_fun, x_end) * 0.5;
	integral *= delta_x;

	t = clock() - t;
	double time_t = ((double)t) / CLOCKS_PER_SEC;
	printf("\nIntegral: %lf\nTime: %f s\n", integral, time_t);

	for (int i = 0; i < c_fun; i++)
		free(function[i]);

	return 0;
}