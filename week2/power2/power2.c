#include <stdio.h>
#include <cs50.c>

int array_elevated(int array[], int num);

int main(void)
{
    int lenght;
    do
    {
        lenght = get_int("Enter array lenght: ");
    }
    while (lenght < 1);

    int array[lenght];
    for (int i = 0; i < lenght; i++)
    {
        array[i] = get_int("Enter array element: ");
    }
    
    // use array_elevated function to elevate each element of array to the power of 2
    array_elevated(array, lenght);
}

int array_elevated(int array[], int num)
{
    for (int i = 0; i < num; i++)
    {
        array[i] = array[i] * array[i];
        printf("%i\n", array[i]);
    }
}