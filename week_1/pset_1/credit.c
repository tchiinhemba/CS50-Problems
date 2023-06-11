#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int luhnValidation(char *cardNumber);
int toNumber(char text);
char *toString(int number);
void checkValidation(char *number, char *cardNumber);

int main(void)
{

    int validationResult = 0;

    string cardNumberAsText = get_string("Number: ");

    for (int i = 0; i < strlen(cardNumberAsText); i++)
    {
        if (isdigit(cardNumberAsText[i]) == false)
        {
            cardNumberAsText = get_string("Number: ");
        }
    }

    validationResult = luhnValidation(cardNumberAsText);

    checkValidation(toString(validationResult), cardNumberAsText);
}

// Luhn Validation
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

void checkValidation(char *number, char *cardNumber)
{
    int bufferItem = strlen(number) - 1;
    int firstDigit = toNumber(cardNumber[0]);

    if (toNumber(number[bufferItem]) == 0)
    {
        switch (firstDigit)
        {
        case 3:
            printf("AMEX\n");
            break;
        case 4:
            printf("VISA\n");
            break;
        case 5:
            printf("MASTERCARD\n");
            break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// convert to number
int toNumber(char text)
{
    return text - '0';
}

// convert to string
char *toString(int number)
{
    char *result = (char *)malloc(20 * sizeof(char));
    sprintf(result, "%d", number);
    return result;
}

void checkBrand(char *number)
{

    for (int i = 0; i < strlen(number); i++)
    {
        if (number)
        {
        }
    }
}
