#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L_MAX 1024
#define N_MAX 100

int compareDesString(const void* str1, const void* str2)
{
    char* const* pp1 = str1;
    char* const* pp2 = str2;
    return -strcmp(*pp1, *pp2);
}

int compareAscString(const void* str1, const void* str2)
{
    char* const* pp1 = str1;
    char* const* pp2 = str2;
    return strcmp(*pp1, *pp2);
}

void sortstring(char* text[], int count, char ascDes)
{
    if(ascDes == '1')
        qsort(text, count, sizeof(*text), compareAscString);
    else
        qsort(text, count, sizeof(*text), compareDesString);
}

int compareDesInt(const void* int1, const void* int2)
{
    const int* n1 = (const int*)int1;
    const int* n2 = (const int*)int2;
    if (*n1 > *n2)
        return 1;
    else
    {
        if (*n1 == *n2)
            return 0;
        else
            return -1;
    }
}

int compareAscInt(const void* int1, const void* int2)
{
    const int* n1 = (const int*)int1;
    const int* n2 = (const int*)int2;
    if (*n1 < *n2)
        return 1;
    else
    {
        if (*n1 == *n2)
            return 0;
        else
            return -1;
    }
}

void sortint(int numbers[], int count, char asscDes)
{
    if (asscDes == '1')
        qsort(numbers, count, sizeof(int), compareDesInt);
    else
        qsort(numbers, count, sizeof(int), compareAscInt);
}


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Please enter two valid program arguments:\n[1] 0 - text, 1 - numbers\n[2] 0 - sort descending, 1 - sort ascending\n");
        return -1;
    }

    if (argv[1][0] == '0')
    {
        char temp[L_MAX];
        char* text[N_MAX];

        int counter = 0;
        while ((fgets(temp, L_MAX, stdin)) != NULL)
            if (temp[0] != '\n')
            {
                text[counter] = malloc(strlen(temp) + 1);
                strcpy(text[counter], temp);
                counter++;
            }

        sortstring(text, counter, argv[2][0]);

        printf("\nSorted:\n");
        for (int i = 0; i < counter; i++)
            printf("%s", text[i]);

        for (int i = 0; i < counter; i++)
            free(text[i]);
    }
    else if (argv[1][0] == '1')
    {
        char temp[L_MAX];
        int numbers[N_MAX];

        int counter = 0;
        while ((fgets(temp, L_MAX, stdin)) != NULL)
        {
            if (temp[0] != '\n' && isdigit(*temp))
            {
                sscanf(temp, "%d", &numbers[counter]);
                counter++;
            }
        }
        
        sortint(numbers, counter, argv[2][0]);
        
        printf("\nSorted:\n");
        for (int i = 0; i < counter; i++)
        {
            printf("%d\n", numbers[i]);
        }
    }

    return 0;
}