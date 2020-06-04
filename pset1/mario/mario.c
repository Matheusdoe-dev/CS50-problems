#include <stdio.h>
#include <cs50.h>

int get_input(void);

int main(void)
{
    int height = get_input();

    for (int x = 1; x <= height; x++)
    {
        for (int c = x; c < height; c++)
        {
            printf(" ");
        }
        for (int y = 1; y <= x; y++)
        {
            printf("#");
        }
        printf("  ");
        for (int a = 1; a <= x; a++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_input(void)
{
    int n;
    do
    {
        n = get_int("What pyramid height want you ?\n");
    }
    while(n < 1 || n > 8);
    return n;
}





