#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) 
{

    string cardNumberAsText = get_string("Number: ");
    int numberState = 0;
    int sum = 0;
    int lastNumber = 0;

    for (int i = 0; i < strlen(cardNumberAsText); i++)
    {
        numberState = cardNumberAsText[i] - '0';

        numberState *= 2;

        if (numberState > 9)
        {
            numberState -= 9;
        }

        sum += numberState;
        i++;
    }

    for (int i = 0; i < strlen(cardNumberAsText); i++)
    {
        i++;
        sum += cardNumberAsText[i] - '0';
    }

    for (int i = 0; i <)


    printf("%i\n", sum);
    
}



// 4220360000559421