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
    if (!file)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE bytes[JPEGRAM];
    fread(bytes, sizeof(BYTE), JPEGRAM, file);

    // Check first three bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3]&0xf0)==0xe0)
    {
        
    }

    }



}