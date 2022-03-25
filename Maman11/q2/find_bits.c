/* This program gets 2 unsigned long numbers and returns how many bits are on (1) in the same spot in both numbers */

#include <stdio.h>

int get_on_bits(int number);

int main()
{
    unsigned long x, y;
    int combined, on_bits;

    /* inputs: get x and y values from stdin */
    printf("Enter number x: ");
    scanf("%lu", &x);

    printf("\nEnter number y: ");
    scanf("%lu", &y);

    printf("\nThe input is: \nx: %lu \ny: %lu", x, y);

    /* combined is a new number, with bit 1 where BOTH x and y have bit 1, and bit 0 where not */
    combined = (x & y);

    /* count on bits (1) in combined (both x and y) */
    on_bits = get_on_bits(combined);

    printf("\n\nNumber of on bits (1) in the same spot in both x and y: %d\n", on_bits);

    return 0;
}