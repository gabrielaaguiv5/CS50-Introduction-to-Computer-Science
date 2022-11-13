#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    //Declare buffer BYTE
    BYTE buffer[512];

    //Declare integer of found images
    int image = 0;

    //Create file for output of found images
    FILE *output = NULL;

    //For jpg files to load in output
    char *filename = malloc(8 * sizeof(char));

    while(fread(buffer, sizeof(char), 512, file))
    {
        //Checking first 4 bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Free data if no found jpeg
            if(output != NULL)
            {
                fclose(output);
            }
            //Load images in output
            sprintf(filename, "%03i.jpg", image);
            output = fopen(filename, "w");

            image++;
        }
        //Load images in output
        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output);
        }
    }
    //Free all memory
    free(filename);
    if(output != NULL)
    {
        fclose(output);
    }
    fclose(file);

     return 0;
}

