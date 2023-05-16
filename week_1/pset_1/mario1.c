
#include <cs50.h>
#include <stdio.h>

int main(void) 
{

    int n = 10;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf(" ");

        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");

    }
}