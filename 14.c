#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L_MAX 100

int main()
{
    double number[L_MAX];
    char* argv;

    int scanSize = 0;
    double temp;
    for (int i = 0; i < L_MAX; i++)
    {
        if (scanf("%lf", &temp) == EOF)
            break;
        number[i] = temp;
        scanSize++;
    }

    double arithmetic_average = 0;
    for (int i = 0; i < scanSize; i++)
    {
        arithmetic_average += number[i];
    }
    arithmetic_average /= (double)scanSize;
    printf("Arithmetic average: %lf\n", arithmetic_average);

    double standard_deviation = 0;
    for (int i = 0; i < scanSize; i++)
    {
        //standard_deviation += (number[i] - (double)scanSize) * (number[i] - (double)scanSize);
        standard_deviation += pow(number[i] - arithmetic_average, 2);
    }
    standard_deviation /= (double)scanSize;
    standard_deviation = sqrt(standard_deviation);
    printf("Standard deviation: %lf\n", standard_deviation);

    return 0;
}