#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct RZYM {
    int arab;
    char* rzym;
} rz[] = { {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},
{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},
{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"} };

void ArToRz(int c)
{
    for (int i = 12; i >= 0; i--)
    {
        while (c >= rz[i].arab)
        {
            c -= rz[i].arab;
            printf("%s", rz[i].rzym);
        }
    }
    printf("\n");
}

void RzToAr(char* c, int size)
{
    int wynik = 0;
    for (int i = 0; i < size; i++)
    {
        switch (c[i])
        {
        case 'I':
            if (i == size - 1)
            {
                wynik++;
                break;
            }
            else
            {
                switch (c[i + 1])
                {
                case 'V':
                    wynik += 4;
                    i++;
                    break;
                case 'X':
                    wynik += 9;
                    i++;
                    break;
                default:
                    wynik++;
                    break;
                }
            }
            break;


        case 'V':
            wynik += 5;
            break;

        case 'X':
            if (i == size - 1)
            {
                wynik += 10;
                break;
            }
            else
            {
                switch (c[i + 1])
                {
                case 'L':
                    wynik += 40;
                    i++;
                    break;
                case 'C':
                    wynik += 90;
                    i++;
                    break;
                default:
                    wynik += 10;
                    break;
                }
            }
            break;


        case 'L':
            wynik += 50;
            break;

        case 'C':
            if (i == size - 1)
            {
                wynik += 100;
                break;
            }
            else
            {
                switch (c[i + 1])
                {
                case 'D':
                    wynik += 400;
                    i++;
                    break;
                case 'M':
                    wynik += 900;
                    i++;
                    break;
                default:
                    wynik += 100;
                    break;
                }
            }
            break;

        case 'D':
            wynik += 500;
            break;

        case 'M':
            wynik += 1000;
            break;

        default:
            break;
        }
    }
    printf("%d", wynik);
    return;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Nie podano liczby");
        return 0;
    }


    if (isdigit(*argv[1]))
    {
        int scan;
        sscanf(argv[1], "%d", &scan);

        printf("%d -- ", scan);
        ArToRz(scan);

        return 0;
    }
    else
    {
        printf("%s -- ", argv[1]);
        RzToAr(argv[1], strlen(argv[1]));
        return 0;
    }
}