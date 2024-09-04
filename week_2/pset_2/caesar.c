#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool validateArguments(int n, string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{

    if (!validateArguments(argc, argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string text = get_string("Plaintext: ");
    string cipherText = text;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        cipherText[i] = rotate(text[i], key);
    }

    printf("ciphertext: %s\n", cipherText);
    
}

char rotate(char c, int key)
{
    if (isalpha(c))
    {
        if (c < 'z' || c < 'Z')
        {
            return c + key;
        } else
        {
            return c + key % 26;
        }
    }
    return c;
}

bool validateArguments(int n, string s)
{
    int digit;

    if (n != 2)
    {
        return false;
    }
    else
    {
        for (int i = 0, len = strlen(s); i < len; i++)
        {
            if (isalpha(s[i]) || ispunct(s[i]) || isblank(s[i]))
            {
                return false;
            }
        }

        if (atoi(s) < 0)
        {
            return false;
        }
    }

    return true;
}