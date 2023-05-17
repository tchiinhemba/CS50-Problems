
#include <cs50.h>
#include <stdio.h>

#define N 20

int main(void) 
{

    
    for (int i = 0; i < N; i++)
    {
        for (int j = N; j > i; j--)
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