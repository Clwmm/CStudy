#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARSIZE 15
#define MAXSIZE 3
#define LIBMAXSIZE 2

struct libr 
{
    int id;
    char name[CHARSIZE];
    char surname[CHARSIZE];
    int numberofbooks;
    char book[MAXSIZE][CHARSIZE];
    char datafrom[MAXSIZE][CHARSIZE];
    char datato[MAXSIZE][CHARSIZE];
};

struct libr in[LIBMAXSIZE];
int libit = 0;

void loadfromfile();
void savetofile();

void printlib();
void printpeople();
void printbooks(int a);

// Menu functions

void addbook();
void addperson();

int main() 
{

    /*struct libr in[2] = 
    {
        {1, "Mateusz", "Kalwa", 2, {"1984", "Folwark"}, {"01.11", "02.11"}, {"05.11", "09.11"}},
        {2, "Ania", "Skamaj", 3, {"Kocham", "Cie", "CB"}, {"01.12", "02.12", "03.12"}, {"05.12", "09.12", "10.12"}}
    };
    for (int i = 0; i < 2; i++)
    {
        printf("%d. %s %s\n", in[i].id, in[i].name, in[i].surname);
        for (int j = 0; j < in[i].numberofbooks; j++)
        {
            printf("\t%s\tFrom: %s\tTo: %s\n", in[i].book[j], in[i].datafrom[j], in[i].datato[j]);
        }
    }*/

    loadfromfile();

    while (1)
    {
        printf("LIBRARY DATABASE\n\t[1] Display database\n\t[2] Add book to person\n\t[3] Add person\n\t[4] Exit\n[] ");
        int cin;
        scanf("%d", &cin);
        switch (cin)
        {
        case 1:
            printlib();
            break;
        case 2:
            addbook();
            break;
        case 3:
            addperson();
            break;
        case 4:
            //savetofile();
            return 0;
        default:
            break;
        }
    }

    return 0;
}


void loadfromfile()
{
    FILE* infile;

    if ((infile = fopen("20.dat", "r")) == NULL)
        infile = fopen("20.dat", "w");

    while (fread(&in[libit], sizeof(struct libr), 1, infile))
        libit++;

    fclose(infile);
}

void savetofile()
{
    FILE* outfile;
    if ((outfile = fopen("20.dat", "w")) == NULL)
    {
        printf("\nError opened file\n");
        exit(1);
    }

    for (int i = 0; i < libit; i++)
        fwrite(&in[i], sizeof(struct libr), 1, outfile);

    if (fwrite == 0)
        printf("Error writing file!\n");

    fclose(outfile);
}

void printlib()
{
    if (libit == 0)
    {
        printf("\n");
        printf("Database is empty. Add person\n");
        printf("\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < libit; i++)
    {
        printf("%d. %s %s\n", in[i].id, in[i].name, in[i].surname);
        for (int j = 0; j < in[i].numberofbooks; j++)
        {
            printf("\t%s\tFrom: %s\tTo: %s\n", in[i].book[j], in[i].datafrom[j], in[i].datato[j]);
        }
    }
    printf("\n");
}

void printpeople()
{
    printf("\n");
    for (int i = 0; i < libit; i++)
        printf("%d. %s %s\n", in[i].id, in[i].name, in[i].surname);
    printf("\n");
}

void printbooks(int a)
{
    printf("\n");
    for (int j = 0; j < in[a].numberofbooks; j++)
    {
        printf("%s\tFrom: %s\tTo: %s\n", in[a].book[j], in[a].datafrom[j], in[a].datato[j]);
    }
    printf("\n");
}



void addbook()
{
    if (libit == 0)
    {
        printf("\n");
        printf("Database is empty. Add person.\n");
        printf("\n");
        return;
    }

    printpeople();
    printf("Choose a person\n[]");
    int cin;
    
    while (1)
    {
        scanf("%d", &cin);
        if (cin > libit || cin < 1)
            printf("Wrong number\n[]");
        else
            break;
    }

    if (in[cin - 1].numberofbooks == MAXSIZE)
    {
        printf("\n");
        printf("The person's database is full\n");
        printf("\n");
        return;
    }

    printf("\t%s %s\n", in[cin - 1].name, in[cin - 1].surname);
    printf("Write the name of the book and the date it was borrowed and returned\n[separated by space]: ");
    char a[CHARSIZE], b[CHARSIZE], c[CHARSIZE];
    scanf("%s %s %s", a, b, c);
    strcpy(in[cin - 1].book[in[cin - 1].numberofbooks], a);
    strcpy(in[cin - 1].datafrom[in[cin - 1].numberofbooks], b);
    strcpy(in[cin - 1].datato[in[cin - 1].numberofbooks], c);
    in[cin - 1].numberofbooks++;
}

void addperson()
{
    if (libit == LIBMAXSIZE)
    {
        printf("\n");
        printf("The library database is full\n");
        printf("\n");
        return;
    }
    printf("Enter name and surname[separated by space]: ");
    char a[CHARSIZE], b[CHARSIZE];
    scanf("%s %s", a, b);
    strcpy(in[libit].name, a);
    strcpy(in[libit].surname, b);
    in[libit].id = libit + 1;
    libit++;
}

// https://www.geeksforgeeks.org/scanf-and-fscanf-in-c/

/*
    char a[] = "Lolz";
    printf("%s\n", a);
    char b[] = "jest";
    strcpy(a, "jestds");
    printf("%s\n", a);

    char b[] = "Mateusz";
    strcpy(in[0].name, b);
*/