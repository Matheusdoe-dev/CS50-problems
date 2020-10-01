#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check if the command line argument format is valid
    // if is bigger or less than 2 arguments, print "Usage: ./recover card.raw", the right way to user, and after return 1
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open memory card
    FILE *memory_card = fopen(argv[1], "r");

    // check if the file pointer is equal no null
    if (!memory_card)
    {
        printf("Invalid file\n");
        return 1;
    }

    // check for each chunk of 512 bytes until the end of the card
    BYTE buffer[512];
    int img_count = 0;
    char *filename = malloc(8);
    while (fread(buffer, 1, 512, memory_card) == 512)
    {
        // if the first four bytes is a valid jpeg header
        if (
            buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff
        )
        {
            // if is the first jpeg
            if (img_count == 0)
            {
                // start to writing a new jpeg file
                sprintf(filename, "%03i.jpg", img_count);
                FILE *img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                fclose(img);
            }
            else
            {
                // close the previous jpeg file that was been created and open a new one to continue writing
                sprintf(filename, "%03i.jpg", img_count);
                FILE *img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                fclose(img);
            }
            img_count++;
        }
        // if the first four bytes is not a valid jpeg header
        else
        {
            // if already found a jepg
            if (img_count != 0)
            {
                // continue to write in the current jpeg file
                FILE *img = fopen(filename, "a");
                fwrite(buffer, 1, 512, img);
                fclose(img);
            }
        }
    }

    // releasing alocated memory
    free(filename);

    // close memory_card file pointer
    fclose(memory_card);

    return 0;
}
