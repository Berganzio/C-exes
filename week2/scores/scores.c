# include <stdio.h>
# include <cs50.c>

const int N = 3;
float flex_average(int lenght, int array[]);

int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Average: %f\n", (score1 + score2 + score3) / (float) 3);
    
    // declaring the integers in a flexible array form
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    // printing the average of the array implementing the average function
    printf("Average: %f\n", flex_average(N, scores));
}

float flex_average(int lenght, int array[])
{
    int sum = 0;
    for (int i = 0; i < lenght; i++)
    {
        sum += array[i];
    }
    return sum / (float) N;
}
