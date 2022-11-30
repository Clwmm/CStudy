#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_SIZE 100
#define MAX_LINES 1000

int main() 
{
    long numbers[MAX_LINES] = { 0 };
    char line[MAX_LINE_SIZE] = { 0 };
    int counter = 0;
    while (fgets(line, MAX_LINE_SIZE, stdin) != NULL && counter < MAX_LINES) {
        numbers[counter] = strtol(line, NULL, 10);
        counter++;
    }
    double arithmetic_average = 0;

    for (int i = 0; i < counter; ++i) {
        arithmetic_average += (double)numbers[i];
    }
    arithmetic_average /= counter;
    printf("arithmetic average %lf\n", arithmetic_average);
    double standard_deviation = 0;
    for (int i = 0; i < counter; ++i) {
        standard_deviation += pow(((double)numbers[i] - arithmetic_average), 2);
    }
    standard_deviation /= counter;
    standard_deviation = sqrt(standard_deviation);

    printf("standard deviation %lf \n", standard_deviation);

}