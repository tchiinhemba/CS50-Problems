#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) 
{

    double number = get_double("Number: ");
    char numberInText[20];

    int firstSum = 0;
    int seccondSum = 0;
    int numberState = 0;

    sprintf(numberInText, "%.0f", number);

    for (int i = 0; i < strlen(numberInText); i++)
    {
        numberState = numberInText[i] - '0';

        if (numberState > 9)
        {
            firstSum += (numberState - 9) * 2;
        }
        firstSum += numberState * 2;
        i++;
        printf("%i", firstSum);
    }
    // printf("%i\n", firstSum);
}


// 4220360000559421