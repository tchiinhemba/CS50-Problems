#include <cs50.h>
#include <stdio.h>

int calculate_years(int start, int end);

int main(void)
{
    int start = 0;
    int end = 0;

    // asking user for start size
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // asking for the end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    int years = calculate_years(start, end);

    printf("Years: %i\n", years);
}

int calculate_years(int start, int end)
{
    int years = 0;

    // Calculate Years
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    // Return the years
    return years;
}
