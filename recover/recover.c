#include <stdio.h>
#include <stdlib.h>

const int JPEGRAM = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
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

    char filename[8]={0};

    BYTE bytes[JPEGRAM];
    fread(bytes, sizeof(BYTE), JPEGRAM, file);

    // Check first three bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3]&0xf0)==0xe0)
    {
        if(output != NULL)
        {
            fclose(output);
        }
        sprintf(filename, "%03d.jpg", jpeg++);
        output = fopen(filename, "w");
    }

    if(output != NULL)
    {
        fclose(output);
    }

    }



}