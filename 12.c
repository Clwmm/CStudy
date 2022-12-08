#include <stdio.h>
#include <string.h>

//puts(char*)

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Text not provided");
		return 0;
	}


	/*
	top:     0     1   2      3
	bot:  0123456 012 012 012345678
	txt:  zadanie spr czy palindrom
	*/

	int top[2] = {1, argc - 1};
	int bot[2] = {0 , strlen(argv[argc-1]) - 1};
	int boolean = 0;

	while (top[0] <= top[1] || bot[0] < bot[1])
	{
		if (bot[0] == strlen(argv[top[0]]))
		{
			top[0]++;
			bot[0] = 0;
		}
		if (bot[1] < 0)
		{
			top[1]--;
			bot[1] = strlen(argv[top[1]]) - 1;
		}

		if (argv[top[0]][bot[0]] != argv[top[1]][bot[1]])
			boolean = 1;

		bot[0]++;
		bot[1]--;
	}

	if (boolean)
		printf("The text is not a palindrome\n");
	else
		printf("The text is a palindrome\n");

	return 0;
}