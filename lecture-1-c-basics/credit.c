#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Function prototypes
int summed_digits(long cardNumber);
int multiply_and_sum(int last_digit);
int count_digits(long cardNumber);
bool is_Amex(long cardNumber, int count_digits);
bool is_MaCard(long cardNumber, int count_digits);
bool is_Visa(long cardNumber, int count_digits);

int main(void)
{
    // Get the card number from the user
    long cardNumber = get_long("cardnumber: ");

    // Calculate the checksum using the Luhn algorithm
    int checksum = summed_digits(cardNumber);

    // Count the number of digits in the card number
    int number_digits = count_digits(cardNumber);

    // Check if the card is an Amex, Mastercard, or Visa
    bool amex = is_Amex(cardNumber, number_digits);
    bool maCard = is_MaCard(cardNumber, number_digits);
    bool visa = is_Visa(cardNumber, number_digits);

    // If the checksum is invalid, print "unvalid"
    if (checksum % 10 != 0)
    {
        printf("unvalid\n");
    }

    // If the card is Amex, print "Amex"
    if (amex == true)
    {
        printf("Amex\n");
    }

    // If the card is Visa, print "visa"
    if (visa == true)
    {
        printf("visa\n");
    }

    // If the card is Mastercard, print "Mastercard"
    if (maCard == true)
    {
        printf("Mastercard\n");
    }
}

// Function to calculate the checksum using the Luhn algorithm
int summed_digits(long cardNumber)
{
    bool every_other_digit = false; // Tracks whether to multiply the digit by 2
    int sum = 0; // Stores the total sum

    while (cardNumber > 0)
    {
        if (every_other_digit == true)
        {
            // If it's an "every other" digit, multiply it by 2 and add its digits to the sum
            int last_digit = cardNumber % 10;
            int product = multiply_and_sum(last_digit);
            sum = sum + product;
        }
        else
        {
            // If it's not an "every other" digit, add it directly to the sum
            int last_digit = cardNumber % 10;
            sum = sum + last_digit;
        }

        // Move to the next digit
        cardNumber = cardNumber / 10;
        every_other_digit = !every_other_digit; // Toggle the flag
    }

    return sum;
}

// Function to multiply a digit by 2 and sum its digits
int multiply_and_sum(int last_digit)
{
    int sum = 0;
    int multiply = last_digit * 2; // Multiply the digit by 2

    // Sum the digits of the product
    while (multiply > 0)
    {
        int other_digit_x2 = multiply % 10;
        sum = sum + other_digit_x2;
        multiply = multiply / 10;
    }

    return sum;
}

// Function to count the number of digits in the card number
int count_digits(long cardNumber)
{
    int sum = 0;

    while (cardNumber > 0)
    {
        cardNumber = cardNumber / 10;
        sum++;
    }

    return sum;
}

// Function to check if the card is an Amex
bool is_Amex(long cardNumber, int number_digits)
{
    // Extract the first two digits
    long first_digit = cardNumber / pow(10, 13);

    // Amex cards have 15 digits and start with 34 or 37
    if (number_digits == 15 && (first_digit == 34 || first_digit == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to check if the card is a Mastercard
bool is_MaCard(long cardNumber, int number_digits)
{
    // Extract the first two digits
    long first_digit = cardNumber / pow(10, 14);

    // Mastercard cards have 16 digits and start with 50-54
    if (number_digits == 16 && (first_digit >= 50 && first_digit <= 54))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to check if the card is a Visa
bool is_Visa(long cardNumber, int number_digits)
{
    // Extract the first digit or first two digits
    int first_digit = cardNumber / pow(10, 14);
    int digit_first = cardNumber / pow(10, 15);

    // Visa cards have 13 or 16 digits and start with 4
    if ((number_digits == 13 || number_digits == 16) && (first_digit == 4 || digit_first == 4))
    {
        return true;
    }
    else
    {
        return false;
    }
}