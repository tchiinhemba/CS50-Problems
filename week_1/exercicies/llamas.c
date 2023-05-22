#include <cs50.h>
#include <stdio.h>

int calculate_years(int start, int end)

int main(void)
{

    int start = get_int("Number of llamas: ");
    int end = get_int("Expect: ");
    int years = calculate_years(start, end)
    

    printf("Years: %i\n", year);
}

int calculate_years(int start, int end)
{
    int year = 0;

    for (int i = start; i < end; i++)
    {
        start = (start / 3) - (start / 4);
        year++;
    }

    return year;
}