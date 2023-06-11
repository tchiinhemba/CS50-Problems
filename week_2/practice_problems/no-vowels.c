// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        switch (argv[1][i])
        {
            case 'e':
                argv[1][i] = '3';
                break;
            case 'o':
                argv[1][i] = '0';
                break;
            case 'i':
                argv[1][i] = '1';
                break;
            default:
                break;
        }
    }
    printf("%s\n", argv[1]);
}
