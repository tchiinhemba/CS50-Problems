#include <stdio.h>
#include <cs50.h>

// get_string and printf with incorrect placeholder
int main(void)
{
    string answer = get_string("What's your name? ");
    printf("Hello, %s\n", answer);
}