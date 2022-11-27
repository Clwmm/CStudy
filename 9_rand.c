#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// ustawianie seedu funkcji rand() aby za ka¿dym razem gdy w³¹czymy program w innym czasie by³y inne wyniki
	srand(time(NULL));

	int circle = 0;
	int square = 0;

	for (int i = 0; i < 1000000000; i++)
	{
		float x = (float)rand() / (float)RAND_MAX;
		float y = (float)rand() / (float)RAND_MAX;

		float r = sqrt((x * x) + (y * y));
		if (r <= 1)
			circle++;
		else
			square++;
	}

	float result = 4 * (float)circle / ((float)circle + (float)square);
	printf("[pi] %f", result);

	return 0;
}