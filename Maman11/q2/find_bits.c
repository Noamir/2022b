/* This program gets 2 unsigned long numbers and returns how many bits are on (1) in the same spot in both numbers */

#include <stdio.h>

int get_on_bits(int number);

int main()
{
    unsigned long x, y;
    int combined, counter;

    /* handle inputs */
    printf("Enter number x: ");
    scanf("%lu", &x);

    printf("\nEnter number y: ");
    scanf("%lu", &y);

    printf("\n\nThe input is: \nx: %lu \ny: %lu", x, y);

    /* combined is a new binary number, with bit 1 where BOTH x and y have bit 1, and bit 0 where not */
    combined = (x & y);

    /* count on bits (1) in combined (both x and y) */
    counter = get_on_bits(combined);

    printf("\n\nNumber of on bits (1) in both x and y: %d\n", counter);

    return 0;
}