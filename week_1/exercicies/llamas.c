#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int start = get_int("Number of llamas: ");
    int end = get_int("Expect: ");
    int year = 0;

    for (int i = start; i < end; i++)
    {
        start = (start / 3) - (start / 4);
        year++;
    }

    printf("Years: %i\n", year);
}