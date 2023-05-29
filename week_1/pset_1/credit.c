#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int luhnValidation(char* cardNumber);
int textNumberToNumber(char text);
char numberToText(int number);

int main(void) 
{

    int validationResult = 0;
    string cardNumberAsText = get_string("Number: ");

    validationResult = luhnValidation(cardNumberAsText);

    printf("%i\n", validationResult);
}


int luhnValidation(char* cardNumber)
{

    int finalSum = 0;
    int individualNumber = 0;

    for (int i = 0; i < strlen(cardNumber); i++)
    {
        individualNumber = textNumberToNumber(cardNumber[i]);

        individualNumber *= 2;

        if (individualNumber > 9)
        {
            individualNumber -= 9;
        }

        finalSum += individualNumber;


        i++;
    }

    for (int i = 0; i < strlen(cardNumber); i++)
    {
        i++;
        finalSum += cardNumber[i] - '0';
    }

    return finalSum;
}


int textNumberToNumber(char text)
{
    return text - '0';
}

char numberToText(int number)
{
    char* text;

    text = (char*) malloc(100 * sizeof(char));

    sprintf(text, "%d", number);

    return text;
}


// 4220360000559421