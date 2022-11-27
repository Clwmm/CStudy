#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Nie podano argumentow\n");
		return -1;
	}

	for (int i = 0; i < strlen(argv[1]); i++)
	{
		printf("%c\n", argv[1][i]);
	}


	//printf("Hello World!");
	return 0;
}