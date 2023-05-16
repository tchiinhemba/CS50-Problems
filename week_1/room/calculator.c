#include <cs50.h>
#include <stdio.h>

int main(void)
{
    

    long x = get_long("x: ");
    long y = get_long("y: ");

    // type casting in C
    float z = (float) x / (float) y;

    // print with 20 numbers after dot
    printf("%.20f\n", z);
}