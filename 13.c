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
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        switch (c[i])
        {
        case 'I':
            if (i == size - 1)
            {
                result++;
                break;
            }
            else
            {
                switch (c[i + 1])
                {
                case 'V':
                    result += 4;
                    i++;
                    break;
                case 'X':
                    result += 9;
                    i++;
                    break;
                default:
                    result++;
                    break;
                }
            }
            break;


        case 'V':
            result += 5;
            break;

        case 'X':
            if (i == size - 1)
            {
                result += 10;
                break;
            }
            else
            {
                switch (c[i + 1])
                {
                case 'L':
                    result += 40;
                    i++;
                    break;
                case 'C':
                    result += 90;
                    i++;
                    break;
                default:
                    result += 10;
                    break;
                }
            }
            break;


        case 'L':
            result += 50;
            break;

        case 'C':
            if (i == size - 1)
            {
                result += 100;
                break;
            }
            else
            {
                switch (c[i + 1])
                {
                case 'D':
                    result += 400;
                    i++;
                    break;
                case 'M':
                    result += 900;
                    i++;
                    break;
                default:
                    result += 100;
                    break;
                }
            }
            break;

        case 'D':
            result += 500;
            break;

        case 'M':
            result += 1000;
            break;

        default:
            break;
        }
    }
    printf("%d\n", result);
    return;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("No number was given\n");
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