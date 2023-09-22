#include <stdio.h>
#include <cs50.c>

int main(void)
{
    // prompt for starting population size
    int start;
    do
    {
        start = get_int("Start size: ");
    } while (start < 9);

    // prompt for ending population size
    int end;
    do
    {
        end = get_int("End size: ");
    } while (end < start);

    // calculate number of years until we reach threshold
    int years = 0;
    int population = start;
    while (population < end)
    {
        population = population + population / 3 - population / 4;
        years++;
    }
    
    // print number of years
    printf("Years: %i\n", years);
}
