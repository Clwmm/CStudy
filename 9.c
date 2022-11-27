#include <math.h>
#include <stdio.h>

// rekurencyjnie zapisanie algorytmu liczb pseudolosowych
int rand(int r)
{
	if (r == 0)
		return (75 * (1) % 65537) - 1;

	return (75 * (rand(r - 1) + 1) % 65537) - 1;
}

// funkcja która konwertuje 
double rand_min(int k)
{
	// Rmax = 2^16 - 1 = 65536 - 1 = 65535
	return ( (double)rand(k)) / (65535);
}

int main()
{
	// zmienna seed do funkcji rand() aby mo¿na by³o u¿ywaæ fuknckji wielokrotnie przy iteracji w funkcji for()
	int seed = 0;

	// sprawdzenie dzia³ania poprzez iteracje funkcji for() oraz u¿ywania zmiennej seed;
	/*for (int i = 0; i < 20; i++)
	{
		printf("[%d]\n", i);
		printf("[x] %lf\n", rand_min(seed));
		seed++;
		printf("[y] %lf\n\n", rand_min(seed));
		seed++;
	}*/

	int circle = 0;
	int square = 0;

	for (int i = 0; i < 32570; i++)
	{
		double x = rand_min(seed);
		seed++;
		double y = rand_min(seed);
		seed++;

		double r = sqrt((x * x) + (y * y));
		if (r <= 1)
			circle++;
		else
			square++;
	}

	double result = 4 * (double) circle / ( (double) circle + (double) square);
	printf("[pi] %lf", result);

	return 0;
}


// Program dzia³a bardzo wolno ze wzglêdu na rekurencyjne obliczanie liczb pseudolosowych