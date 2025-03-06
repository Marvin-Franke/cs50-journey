#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function declaration
int score(string word, string letters, int *points, int b);

int main(void)
{
    // Array of points for each letter (like in Scrabble)
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    
    // Array of uppercase letters A-Z
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Get words from both players
    string player_one = get_string("player1: ");
    string player_two = get_string("player2: ");
    
    // Calculate the length of each word
    int lenght1 = strlen(player_one);
    int lenght2 = strlen(player_two);
    
    // Calculate the scores for each player
    int score_pOne = score(player_one, letters, points, lenght1);
    int score_two = score(player_two, letters, points, lenght2);

    // Determine the winner or if it's a tie
    if (score_pOne > score_two)
    {
        printf("player 1 wins!\n");
    }
    else if (score_pOne < score_two)
    {
        printf("player 2 wins!\n");
    }
    else
    {
        printf("tie!\n");
    }
}

// Function to calculate the score of a word
int score(string word, string letters, int *points, int b)
{
    int scores = 0;
    
    for (int i = 0; i < b; i++)
    {
        int a = 0;
        
        // Check if the character is a letter
        if (isalpha(word[i]) != 0)
        {
            // Convert the letter to uppercase
            word[i] = toupper(word[i]);

            // Find the matching letter in the letters array
            if (word[i] == letters[a])
            {
                scores += points[a]; // Ad points if it's a direct match
            }
            else
            {
                // Loop through the array until the letter is found
                while (word[i] != letters[a])
                {
                    a++;
                }
                scores += points[a]; // Ad the points for the found letter
            }
        }
    }
    
    // Return the total score
    return scores;
}
