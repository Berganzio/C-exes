#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    else if (argv[1] == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    // open memory card
    FILE *file = fopen(argv[1], "r");

    // iterate through every slot in memory card
    unsigned char buffer[512];
    int counter = 0;
    char filename[8];
    FILE *img = NULL;
    while (fread(buffer, 512, 1, file) == 1)
    {
        // check if start of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // close previous jpeg
            if (counter > 0)
            {
                fclose(img);
            }

            // create new jpeg
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }

        // write to jpeg
        if (counter > 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    // close files
    fclose(file);
    fclose(img);
    return 0;
}