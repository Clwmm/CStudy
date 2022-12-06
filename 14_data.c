#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	FILE* f1;
	f1 = fopen("14_data.dat", "w");

	for (int i = 0; i < 1000; i++)
		fprintf(f1, "%lf\n", (double)rand() / (RAND_MAX + 1.0));

	fclose(f1);

	return 0;
}