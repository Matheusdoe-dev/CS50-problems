#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    int j = 0;
    int key = 0;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // else are one command line argument
        for (int i = 0; argv[1][i]; i++)
        {
            if (argv[1][i] < 48 || argv[1][i] > 57)
            {
                // if any char is not a digit
                j = 0;
                printf("Usage: ./caesar key\n");
                return 1;
                break;
            }
            else
            {
                // else is a digit
                j = 1;
            }
        }
        if (j == 1)
        {
            // encrypt function
            key = atoi(argv[1]);
            // get user input
            string plaintext = get_string("\nplaintext: ");
            for (int x = 0; plaintext[x]; x++)
            {
                // that p is to convert each char in a number into 1 to 26
                int p = 0;
                // if is uppercase
                if (plaintext[x] >= 65 && plaintext[x] <= 90)
                {
                    p = (plaintext[x] - 64) + key;
                    if (p > 26)
                    {
                        plaintext[x] = (p % 26) + 64;
                    }
                    else
                    {
                        plaintext[x] = p + 64;
                    }
                }
                // if is lowercase
                else if (plaintext[x] >= 97 && plaintext[x] <= 122)
                {
                    p = (plaintext[x] - 96) + key;
                    if (p > 26)
                    {
                        plaintext[x] = (p % 26) + 96;
                    }
                    else
                    {
                        plaintext[x] = p + 96;
                    }
                }
            }
            string ciphertext = plaintext;
            printf("ciphertext: %s\n", (string) ciphertext);
        }
    }
}