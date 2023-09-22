#include <stdio.h>
#include <cs50.c>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Incorrect app usage. Please try again.");
        return 1;
    }
    else
    {
        // check if buffer returns pdf initial values
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            printf("Could not open file.");
            fclose(file);
            return 1;
        }
        else
        {
            // read first 4 bytes of file
            uint8_t buffer[4];                       // unsigned integer type of 8 bits, always positive
            uint8_t signature[4] = {37, 80, 68, 70}; // these are the first 4 bytes of a pdf file, always.
            fread(buffer, 4, 1, file);
            fclose(file);
            // compare first 4 bytes of file to pdf signature
            for (int i = 0; i < 4; i++)
            {
                if (buffer[i] != signature[i])
                {
                    printf("File is not a pdf.");
                    return 1;
                }
            }
            printf("File is a pdf.");
        }
    }
}
