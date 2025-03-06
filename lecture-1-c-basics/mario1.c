#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Obtains input of the value n by the user between 1 and 8 inclusive
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Loop to create n rows
    for (int i = 0; i < n; i++)
    {
        // Loop to create columns for the first half of the pyramid
        for (int j = 0; j < n; j++)
        {
            // Outputs spaces to arrange the semi-pyramid of # in the correct direction
            if (i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                // Outputs # to form the diagonal of the first half
                printf("#");
            }
        }

        // Creates space between the first and second half of the pyramid
        printf(" ");

        // Loop to create the second half of the pyramid
        for (int k = n; k > 0; k--)
        {
            // Outputs # to form the diagonal of the second half
            if (i + k > n - 1)
            {
                printf("#");
            }
        }

        // Moves to the next line after completing a row
        printf("\n");
    }
}