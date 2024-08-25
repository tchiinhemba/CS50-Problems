#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");

    } while (height > 8 || height < 1);

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
        printf("\n");
    }
}