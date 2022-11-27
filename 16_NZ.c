#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Nie podano pliku");
		return 0;
	}

	FILE* file1;
	FILE* file2;
	
	char Tymczasowy[L_tmpnam + 1];
	tmpnam(Tymczasowy);

	if (NULL == (file1 = fopen(argv[1], "rb")))
		return 1;
	if (NULL == (file2 = fopen(Tymczasowy, "wb")))
		return 1;

	double x;
	while (EOF != scanf("%lf", &x))
	{
		printf("%lf\n", x);
	}

	/*int znak;
	while ((znak = getc(file1)) != EOF)
	{
		znak++;
		putc(znak, stdout);
	}*/

	//unlink(argv[1]);
	//rename(Tymczasowy, argv[1]);


	printf("\nHello World!");
	return 0;
}

/*
*/