#include <stdio.h>

int get_int(void);
char *get_string(void);

int main(void)
{
    int n = get_int();
    char *s = get_string();
    printf("%i\n", n);
    printf("%s\n", s);
}

// create get_int function
int get_int(void)
{
    int n;
    printf("n is: ");
    scanf("%i", &n);
    return n;
}

// create get_string function
char *get_string(void)
{
    char *s = NULL;
    // allocate memory for s
    s = malloc(10 * sizeof(char));
    printf("s is: ");
    scanf("%s", s);
    return s;
}