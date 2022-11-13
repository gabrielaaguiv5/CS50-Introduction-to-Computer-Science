// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Typedef functions to use in the programs body
typedef uint8_t HEADER;
typedef int16_t BUFFER;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    //To lock bytes of header
    HEADER header[HEADER_SIZE];

    //Copying address and content of header from input to output
    fread(header, sizeof(HEADER), HEADER_SIZE, input);
    fwrite(header, sizeof(HEADER), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    BUFFER buffer;

    //Buffer is a temp variable to store content while amping by factor
    while (fread(&buffer, sizeof(BUFFER), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(BUFFER), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
