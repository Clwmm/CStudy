#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("You must provide the file access path and password");
		return 1;
	}

	int passwordL = strlen(argv[2]);

	FILE* file1;
	if (NULL == (file1 = fopen(argv[1], "rb")))
		return -1;

	char temp[256];
	tmpnam(temp);

	FILE* file2;
	if (NULL == (file2 = fopen(temp, "wb")))
		return -1;

	char cha;
	int i = 0;
	while ((cha = getc(file1)) != EOF)
	{
		cha ^= argv[2][i % (passwordL)];
		i++;
		putc(cha, file2);
		putc(cha, stdout);
	}

	unlink(argv[1]);
	rename(temp, argv[1]);

	fclose(file1);
	fclose(file2);

	return 0;
}
