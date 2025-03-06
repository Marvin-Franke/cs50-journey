#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function declarations
int countletters(string text, int length);
int countwords(string text, int length);
int punkte(int letters, int words, int countSents);
int sentences(string text, int length);

int main(void)
{
    // Get the text input from the user
    string text = get_string("text: ");
    
    // Calculate the length of the text
    int length = strlen(text);
    
    // Count the number of letters, words, and sentences
    int letters = countletters(text, length);
    int words = countwords(text, length);
    int countSents = sentences(text, length);
    
    // Calculate the grade level
    int grade = punkte(letters, words, countSents);

    // Print the grade level or a special message for very low or high grades
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        // Print the grade level or 16+ for very high levels
        switch (grade)
        {
            case 1: case 2: case 3: case 4: case 5: 
            case 6: case 7: case 8: case 9: case 10:
            case 11: case 12: case 13: case 14: case 15:
                printf("Grade: %i\n", grade);
                break;
            default:
                printf("Grade: 16+ ");
                break;
        }
    }
}

// Function to count the number of letters in the text
int countletters(string text, int length)
{
    int score = 0;
    
    for (int i = 0; i < length; i++)
    {
        // Check if the character is a letter
        if (isalpha(text[i]))
        {
            score++;
        }
    }
    return score;
}

// Function to count the number of words in the text
int countwords(string text, int length)
{
    int score = 0;

    for (int i = 0; i <= length; i++)
    {
        // Count spaces, newlines, or the end of the string as word separators
        if (!isalpha(text[i]))
        {
            if (text[i] == ' ' || text[i] == '\n' || text[i] == '\0')
            {
                score++;
            }
        }
    }
    return score;
}

// Function to count the number of sentences in the text
int sentences(string text, int length)
{
    int score = 0;

    for (int i = 0; i < length; i++)
    {
        // Check for sentence-ending punctuation
        if (!isalpha(text[i]))
        {
            if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
                score++;
            }
        }
        // Count the last sentence if the string ends
        else if (text[i + 1] == '\0')
        {
            score++;
        }
    }
    return score;
}

// Function to calculate the Coleman-Liau index (grade level)
int punkte(int letters, int words, int countSents)
{
    // Use the Coleman-Liau formula
    double index = (0.0588 * ((double) letters / words) * 100) -
                   0.296 * (((double) countSents / words) * 100) - 15.8;

    // Round the result to the nearest integer
    double faktor = (pow(10.0, 2));
    index = round(faktor * index) / faktor;
    index = round(index);

    return index;
}