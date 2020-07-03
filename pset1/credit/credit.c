#include<stdio.h>
#include<cs50.h>

int creditCardCheck(void);

int main(void)
{
    // printf("Use this program to check if a credit card number is valid\n and check what flag is\n");
    unsigned int result = creditCardCheck();
    printf("%i\n", result);
}

int creditCardCheck(void)
{
    long cardNumber = get_long("Input you credit card number\n");
    int sum = 0;
    int pro = 0;
    int current;
    for (int i = 1; i < 18; i++)
    {
        current = cardNumber % 10;
        if (i % 2 == 1)
        {
            sum += current;
            printf("%lo,%i,%i\n", cardNumber, current, sum);
        }

        if (i % 2 == 0)
        {
            pro += current * 2;
            printf("%lo,%i,%i\n", cardNumber, current, sum);
        }
        cardNumber = cardNumber / 10;
    }
    unsigned int checksum = sum;
    return checksum;
}