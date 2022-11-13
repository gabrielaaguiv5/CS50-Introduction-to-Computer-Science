#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned char buffer[512];
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
        return 1;
    }

    int image = 0;

    FILE *output = NULL;

    char *filename = malloc(8 * sizeof(char));

    BYTE bytes[JPEGRAM];
    while(fread(bytes, sizeof(BYTE), JPEGRAM, file))
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3]&0xf0)==0xe0)
        {
            sprintf(filename, "%03d.jpg", image++);
            output = fopen(filename, "w");

            image++;
        }

        if (output != NULL)
        {
            fwrite(bytes, sizeof(BYTE), JPEGRAM, output);
        }
    }
    free(filename);
    fclose(output);
    fclose(file);

return 0;
}

