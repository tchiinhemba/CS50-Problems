#include <cs50.h>
#include <stdio.h>

int main(void)
{

    char c = get_char("Do you agree? ");

    if (c == 'n' || c == 'N')
    {
        printf("Not agreed\n");
    }
    else if (c == 'y' || c == 'Y')
    {
        printf("Agreed\n");
    }
}