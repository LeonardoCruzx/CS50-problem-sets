#include <stdio.h>
// include cs50 files
#include <cs50.h>

int main(void)
{
    bool multiply = false;
    int sumMultiply = 0;
    int sumWithoutMultiply = 0;
    long number = get_long("Number: \n");
    int firstNumbers = 0;
    bool findedFirstNumbers = false;
    int size = 0;
    while (number > 0)
    {
        // sum numbers multiplying
        if (multiply)
        {
            multiply = false;
            // verifiy if the digit is greather than 9
            if (((number % 10) * 2) > 9)
            {
                long aux = (number % 10) * 2;
                // broke into new digits and sum them
                while (aux > 0)
                {
                    sumMultiply += aux % 10;
                    aux /= 10;
                }
                
            }
            // else sum the number
            else
            {
                sumMultiply += (number % 10) * 2;
            }
            
        }
        // sum numbers without multiply
        else
        {
            multiply = true;
            sumWithoutMultiply += (number % 10);
        }
        // verify if the number divided by 1000 is lower than 100
        if (!(number / 1000 > 100))
        {
            // verify if number module 10000 is lower than 100 and findedfirstnumbers is false
            if (number % 10000 < 100 && !findedFirstNumbers)
            {
                firstNumbers = number % 1000;
                findedFirstNumbers = true;
            }
        }
        
        number /= 10;
        size++;
    }
    // sum the multiply and not multiplyed sums
    int totalSum = sumMultiply + sumWithoutMultiply;
    
    if ((firstNumbers > 39 && firstNumbers < 43) && totalSum % 10 == 0 && size > 11)
    {
        printf("VISA\n");
    }
    else if ((firstNumbers > 50 && firstNumbers < 56) && totalSum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else if ((firstNumbers == 34 || firstNumbers == 37) && totalSum % 10 == 0)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}