#include <stdio.h>
// include cs50 files
#include <cs50.h>

int main(void)
{
    int number = 0;
    // get a input from user while the number is lower than one or greather than eight
    do
    {
        number = get_int("number: \n");
    }
    while (number < 1 || number > 8);

    int col = number;
    
    for (int i = 1; i <= number; i++)
    {
        printf("");
        // prints white spaces in the left of the first collumn
        for (int z = 1; z < col; z++)
        {
            printf(" ");
        }
        col--;
        // prints the first collumn of #
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        // prints the second collumn of #
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}