#include<stdio.h>
#include<cs50.h>
#include<math.h>

float greedyAlgorithm(void);

int main(void)
{
    int result = greedyAlgorithm();
    printf("%i coins\n", result);
}

float greedyAlgorithm(void)
{
    // get user input and check if is positive float
    float changeOwed;
    do
    {
        changeOwed = get_float("Change owed: \n");
    }
    while (changeOwed <= 0);

    // greedy algorithm
    changeOwed = round(changeOwed * 100);
    int coins = 0;

    /// quarters
    while (changeOwed >= 25)
    {
        changeOwed = changeOwed - 25;
        coins++;
    }

    // Dimes
    while (changeOwed >= 10)
    {
        changeOwed = changeOwed - 10;
        coins++;
    }

    // Nickels
    while (changeOwed >= 5)
    {
        changeOwed = changeOwed - 5;
        coins++;
    }

    // Pennies
    while (changeOwed >= 1)
    {
        changeOwed = changeOwed - 1;
        coins++;
    }

    return coins;
}