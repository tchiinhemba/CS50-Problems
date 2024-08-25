#include <cs50.h>
#include <stdio.h>

int main()
{
    int height;

    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);


    for (int i = 0; i < height; i++)
    {
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
         
         printf(" ");

         for (int l = 0; l <= i; l++)
         {
            printf("#");
         }
         
         printf("\n");

    }
    
}