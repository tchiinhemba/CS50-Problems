#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int counter_letter(string text);
int counter_words(string text);
int counter_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = counter_letter(text);
    int words = counter_words(text);
    int sentences = counter_sentences(text);

    float l = ((float)letters / words) * 100;
    float s = ((float)sentences / words) * 100;

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int counter_letter(string text)
{
    int counter = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

int counter_words(string text)
{
    int counter = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

int counter_sentences(string text)
{
    int counter = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            counter++;
        }
    }

    return counter;
}