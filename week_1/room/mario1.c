#include <cs50.h>
#include <stdio.h>

int size(void);

int main(void)
{

    int n = size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}


int size(void)
{
    const int size = get_int("Size of your block? ");
    return size;
}

