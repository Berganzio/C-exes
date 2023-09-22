#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.c>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("n is %i\n", n);              // print the value of n
    printf("*p is %i\n", *p);            // print the value of n using p (dereferencing)
    printf("n's address is at %p\n", p); // print the address of n

    char *s = "EMMA";
    printf("s is %s\n", s);                     // print the value of s
    printf("s's address is at %p\n", s);        // print the address of s
    printf("s[0] is %c\n", s[0]);               // print the value of s[0]
    printf("s[0]'s address is at %p\n", &s[0]); // print the address of s[0]
    printf("s[1] is %c\n", s[1]);               // print the value of s[1]
    printf("s[1]'s address is at %p\n", &s[1]); // print the address of s[1]
    printf("s[2] is %c\n", s[2]);               // print the value of s[2]
    printf("s[2]'s address is at %p\n", &s[2]); // print the address of s[2]

    // you can also add to the address of a variable to get the address of the next variable
    printf("s[0]'s address is at %p\n", &s[0]);     // print the address of s[0]
    printf("s[1]'s address is at %p\n", &s[0] + 1); // print the address of s[1]
    printf("s[2]'s address is at %p\n", &s[0] + 2); // print the address of s[2]
    printf("s[3]'s address is at %p\n", &s[0] + 3); // print the address of s[3]
    printf("s[4]'s address is at %p\n", &s[0] + 4); // print the address of s[4] (null character)
}

// the address of s is the same as the address of s[0] because
// the string is stored in a contiguous block of memory
// so the address of s is the address of the first character in the string
// the comouter then knows that the next character is at the next address
// and the next character is at the next address, etc. until it reaches the null character ("\0")