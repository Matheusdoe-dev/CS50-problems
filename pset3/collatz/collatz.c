#include<stdio.h>
#include<cs50.h>

void collatz(int n);

int main (void)
{
    int n = get_int("N: ");
    collatz(n);
}

void collatz(int n)
{
    int steps = 0;
    int i = n;
    while (i != 1)
    {
        if (i % 2 == 0)
        {
            i /= 2;
            steps++;
        } else if (i % 2 != 0)
        {
            i = (3 * i) + 1;
            steps++;
        }
    }
    printf("Steps: %i\n", steps);
}