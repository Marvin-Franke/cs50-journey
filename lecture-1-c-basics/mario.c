#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declare a variable to store the height of the pyramid
    int n;

    // Keep asking the user for the height until they enter a number between 1 and 8
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Loop through each row of the pyramid
    for (int i = 0; i < n; i++)
    {
        // Loop through each column in the current row
        for (int j = 0; j < n; j++)
        {
            // If the current position is before the start of the pyramid, print a space
            if (i + j < n - 1)
            {
                printf(" ");
            }
            // Otherwise, print a "#" to build the pyramid
            else
            {
                printf("#");
            }
        }
        // Move to the next line after finishing a row
        printf("\n");
    }
}