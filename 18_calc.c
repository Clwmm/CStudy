#include "18_calc.h"

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

double heap[MAXSIZE];
int heapi = 0;

double calc(char* function[], int c_fun, double x)
{
    char argv[MAXSIZE];
	for (int i = 0; i < c_fun; i++)
	{
        strcpy(argv, function[i]);

        if (isdigit(*argv))
        {
            // Positive number
            double scan;
            sscanf(argv, "%lf", &scan);
            push(scan);
        }
        else
        {
            // Negative number
            if (argv[0] == '-' && argv[1] != '\n')
            {
                char temp[MAXSIZE - 1];
                for (int i = 1; i < MAXSIZE; i++)
                {
                    temp[i - 1] = argv[i];
                    if (argv[i] == '\n')
                        break;
                }

                if (isdigit(*temp))
                {
                    double scan;
                    sscanf(temp, "%lf", &scan);
                    push(scan);
                }
            }

            // Trigonometric functions
            if (strncmp(argv, "sin", 3) == 0)
                push(sin(pop()));
            if (strncmp(argv, "cos", 3) == 0)
                push(cos(pop()));
            if (strncmp(argv, "tan", 3) == 0)
                push(tan(pop()));

            // Logarithm
            if (strncmp(argv, "log", 3) == 0)
                push(log(pop()));

            if (strncmp(argv, "**", 2) == 0)
            {
                double x = pop();
                double y = pop();
                push(pow(y, x));
            }
            else if (strncmp(argv, "*", 1) == 0)
            {
                double x = pop();
                double y = pop();
                push(x * y);
            }

            // Calculations
            switch (*argv)
            {
            case 'q':
                return 0;

            case 'x':
                push(x);
                break;

            case '+':
            {
                double x = pop();
                double y = pop();
                push(x + y);
                break;
            }
            case '-':
            {
                double x = pop();
                double y = pop();
                push(y - x);
                break;
            }
            case '/':
            {
                double x = pop();
                double y = pop();
                push(y / x);
                break;
            }
            case '=':
                printf("= %.1lf\n", heap[heapi - 1]);
                break;

            default:
                break;
            }
        }
	}
    return pop();
}

double pop()
{
    heapi--;
    return heap[heapi];
};

void push(double a)
{
    heap[heapi] = a;
    heapi++;
};
