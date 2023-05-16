// Conditionals, Boolean expressions, relational operators

#include <stdio.h>
#include <cs50.h>

int main()
{

    // Prompt user for integers
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    // Compare integers
    if (x < y)
    {
        printf("x is less than y\n");
    }
}