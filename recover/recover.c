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

    BYTE buffer[512];

    int image = 0;

    FILE *output = NULL;

    char *filename = malloc(8 * sizeof(char));

    while(fread(buffer, sizeof(char), 512, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", image);
            output = fopen(filename, "w");

            image++;
        }


        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output); fclose(output);
            fclose(output);
        }
    }
    
    free(filename);
    fclose(output);
    fclose(file);

return 0;
}

