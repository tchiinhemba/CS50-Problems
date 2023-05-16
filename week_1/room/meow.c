#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    int times = get_int("How many times do you want meow? ");
    printf("\n");
    meow(times);
}


void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Meow!\n");
    }
}