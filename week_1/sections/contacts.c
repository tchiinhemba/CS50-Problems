#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");
    string numberPhone = get_string("What is yur number phone? ");

    printf("Name: %s\n", name);
    printf("Age: %i\n", age);
    printf("Numer: %s\n", numberPhone);

    return 0;
}