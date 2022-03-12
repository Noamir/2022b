#include <stdio.h>

int main()
{
    /* variables */
    unsigned long x, y;
    int combined, counter = 0;

    /* inputs */
    printf("Enter number x: ");
    scanf("%lu", &x);

    printf("Enter number y: ");
    scanf("%lu", &y);

    printf("\nThe input is: \nx: %lu, y: %lu\n", x, y);

    /* if x and y have bit 1 in the same index - insert 1 to combined index. if only one of them is 1 \ both 0 - insert 0 */
    /* which mean combined contains the number of 1s which are mutual - this is what we need to count! */
    combined = (x & y); 

    /* go over combined - if 1 count, if 0 don't, shift right after every time to go over all */
    while (combined > 0) /* each shift right, it put 0 on the right instead, so eventually we will have 00000000000000000000000000000000 == 0 */
    {
        if ((combined & 1) == 1) /* check the right bit (MSB) of combined - if it's 1 - count it */
            counter++;

        /* We checked the most right bit, don't need it anymore - shift combined bits to the right */
        combined = combined >> 1; /* next time we will check the next bit */
    }

    printf("\ncounter: %d\n", counter); /* 1 bits */

    return 0;
}