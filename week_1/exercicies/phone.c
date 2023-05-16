#include <cs50.h>
#include <stdio.h>


int main(void)
{

    string name = get_string("Name: ");
    int age = get_int("Age: ");
    string phoneNumber = get_string("Phone number: ");

    printf("Name: %s;\n Age: %i;\n Phone: %s;\n", name, age, phoneNumber);
}