int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{   
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

//obliges the user to enter an amount greater than 0.
int get_cents(void)
{
    int amount;

    do
    {
        amount = get_int("Amount: ");
    }
    while (amount <= 0);
    return amount;
}

// deducts the next unit of coins and counts how many times this unit has been deducted.
int calculate_quarters(int cents)
{
    int c = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        c++;
    }
    return c;
}

// deducts the next unit of coins and counts how many times this unit has been deducted.
int calculate_dimes(int cents)
{

    int d = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        d++;
    }
    return d;
}
// deducts the next unit of coins and counts how many times this unit has been deducted.
int calculate_nickels(int cents)
{
    int n = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        n++;
    }
    return n;
}
// deducts the next unit of coins and counts how many times this unit has been deducted.
int calculate_pennies(int cents)
{
    int p = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        p++;
    }
    return p;
}