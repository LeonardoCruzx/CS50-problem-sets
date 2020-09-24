#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int isNumber(char *text);
char rotateChar(char c, int iterations);
char *cipherText(char *text, int iterations);

int main(int argc, char **argv)
{
    // verify if argc has more or less than 1 argument
    if (argc != 2)
    {
        printf("Please insert one parameter!\n");
        return 1;
    }
    // verify if the argument is a number
    if (!isNumber(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // getting text from user
    string plainText = get_string("plaintext: ");
    // cipher the text
    string a = cipherText(plainText, atoi(argv[1]));
    printf("ciphertext: %s", a);
    printf("\n");
    return 0;
}

// verify if a char is a number
int isNumber(char *text)
{
    int j;
    j = strlen(text);
    while (j--)
    {
        if (text[j] >= '0' && text[j] <= '9')
        {
            continue;
        }
        return 0;
    }
    return 1;
}

//receives the number of iterations and a char and returns a rotated char
char rotateChar(char c, int iterations)
{
    // enter only if the char is uppercase
    if (c < 91 && c > 64)
    {
        while (iterations != 0)
        {
            c++;
            if (c == 91)
            {
                c = 65;
            }
            iterations--;
        }

    }
    // enter only if the char is lowercase
    else if (c < 123 && c > 96)
    {
        while (iterations != 0)
        {
            c++;
            if (c == 123)
            {
                c = 97;
            }
            iterations--;
        }
    }
    return c;
}

// receive a text and the number of iterations of each char and returns a cipher text
char *cipherText(char *text, int iterations)
{
    // iterate over the text and changes every char
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = rotateChar(text[i], iterations);
    }
    return text;
}