#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./reverse <input.wav> <output.wav>\n");
        return 1;
    }

    // Open input file for reading
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Unable to open input file %s\n", argv[1]);
        return 2;
    }

    // Read header
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input_file);

    // Use check_format to ensure WAV format
    if (check_format(header) != 0)
    {
        fprintf(stderr, "Input file is not in WAV format\n");
        return 3;
    }

    // Open output file for writing
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        fprintf(stderr, "Unable to open output file %s\n", argv[2]);
        return 4;
    }

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, output_file);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);

    // Calculate number of blocks in audio data
    int num_blocks = header.subchunk2Size / block_size;

    // Allocate memory for audio data
    int16_t *audio_data = (int16_t *)malloc(header.subchunk2Size);

    // Read audio data from input file
    fread(audio_data, sizeof(int16_t), num_blocks * block_size / sizeof(int16_t), input_file);

    // Reverse audio data
    for (int i = 0; i < num_blocks * block_size / sizeof(int16_t) / 2; i++)
    {
        int16_t temp = audio_data[i];
        audio_data[i] = audio_data[num_blocks * block_size / sizeof(int16_t) - i - 1];
        audio_data[num_blocks * block_size / sizeof(int16_t) - i - 1] = temp;
    }

    // Write reversed audio to file
    fwrite(audio_data, sizeof(int16_t), num_blocks * block_size / sizeof(int16_t), output_file);

    // Free allocated memory
    free(audio_data);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

int check_format(WAVHEADER header)
{
    // check the header to see if it is a WAV file.
    if (header.chunkID[0] != 'R' || header.chunkID[1] != 'I' || header.chunkID[2] != 'F' || header.chunkID[3] != 'F')
    {
        return 1;
    }
    else if (header.format[0] != 'W' || header.format[1] != 'A' || header.format[2] != 'V' || header.format[3] != 'E')
    {
        return 1;
    }
    else if (header.subchunk1ID[0] != 'f' || header.subchunk1ID[1] != 'm' || header.subchunk1ID[2] != 't' || header.subchunk1ID[3] != ' ')
    {
        return 1;
    }
    else if (header.subchunk2ID[0] != 'd' || header.subchunk2ID[1] != 'a' || header.subchunk2ID[2] != 't' || header.subchunk2ID[3] != 'a')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_block_size(WAVHEADER header)
{
    return header.blockAlign;
}