#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int grade();
int getQtdWords(string);
float avgLetter(string, int);
float avgSentence(string, int);

int main(void)
{
    // get text from user
    string text = get_string("\nText: ");
    // send text to function grade
    int g = grade(text);
    //if g is less than one
    if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    // if g is greather than fifteen
    else if (g > 15)
    {
        printf("Grade 16+\n");
    }
    // if g is betwen 15 and 1
    else
    {
        printf("Grade %i\n", g);
    }
}

// return the rounded grade
int grade(string text)
{
    int qtdWords = getQtdWords(text);
    float avgLetters = avgLetter(text, qtdWords);
    float avgSentences = avgSentence(text, qtdWords);
    float value =  0.0588 * avgLetters - 0.296 * avgSentences - 15.8;
    return round(value);
}

// return qtd of words in a text
int getQtdWords(string text)
{
    int qtdWords = 1;
    int textLen = strlen(text);
    for (int i = 0; i < textLen; i++)
    {
        char letter = text[i];
        // check if the letter is a space
        if (letter == 32)
        {
            qtdWords++;
        }
        // check if the letter is a ' 
        else if (letter == 39)
        {
            // check if the letter in front of is a s
            if (text[i + 1] != 115)
            {
                qtdWords++;
            }
        }
    }
    return qtdWords;
}

// return the avg of letters in a text
float avgLetter(string text, int qtdWords)
{
    
    int textLen = strlen(text);
    int qtdLetters = 0;
    
    for (int i = 0; i < textLen; i++)
    {
        char letter = text[i];
        if (letter < 123 && letter > 96)
        {
            qtdLetters++;
        }
        else if (letter < 91 && letter > 64)
        {
            qtdLetters++;
        }
    }
    return (qtdLetters * 100) / qtdWords;
}

// return avg of sentences in a text
float avgSentence(string text, int qtdWords)
{
    int textLen = strlen(text);
    int qtdSentences = 0;
    
    for (int i = 0; i < textLen; i++)
    {
        char letter = text[i];
        if (letter == 46 || letter == 63 || letter == 33)
        {
            qtdSentences++;
        }
    }
    return (qtdSentences * 100) / qtdWords;
}