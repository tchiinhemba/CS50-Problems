#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int luhnValidation(char *cardNumber);
int toNumber(char text);
char *toString(int number);
void checkValidation(char *number);

int main(void)
{

    int validationResult = 0;

    string cardNumberAsText = get_string("Number: ");

    for (int i = 0; i < strlen(cardNumberAsText); i++)
    {
        if (cardNumberAsText[i] == '-')
        {
            cardNumberAsText = get_string("Number: ");
        }
    }

    validationResult = luhnValidation(cardNumberAsText);

    checkValidation(toString(validationResult));
}

int luhnValidation(char *cardNumber)
{

    int finalSum = 0;
    int individualNumber = 0;

    for (int i = 0; i < strlen(cardNumber); i++)
    {

        individualNumber = toNumber(cardNumber[i]);
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
        finalSum += toNumber(cardNumber[i]);
    }
    return finalSum;
}

void checkValidation(char *number)
{
    int bufferItem = strlen(number) - 1;

    if (toNumber(number[bufferItem]) == 0)
    {
        printf("VALID\n");
        return;
    }
    printf("INVALID\n");
}

int toNumber(char text)
{
    return text - '0';
}

char *toString(int number)
{
    char *result = (char *)malloc(20 * sizeof(char));
    sprintf(result, "%d", number);
    return result;
}

// 4220360000559421