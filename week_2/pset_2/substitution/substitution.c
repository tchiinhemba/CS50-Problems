#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{

    if (argc != 2)

}



char rotate(char s)
{

}


bool validateArguments(string promptInput)
{
    int str_len = strlen(promptInput);

    if (str_len < 26)
    {
        return;
    }

    for (int i = 0; i < str_len; i++)
    {
        printf("%c", promptInput[i]);
    }
}