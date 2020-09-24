#include <stdio.h>
// include cs50 files
#include <cs50.h>

int main(void)
{
    // gets a string from user
    string name = get_string("What is your name?\n");
    // prints hello and a string 
    printf("hello, %s\n", name);
}