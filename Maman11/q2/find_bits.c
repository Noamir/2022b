#include <stdio.h>

/* int unsignedLongToBit(unsigned long num)
{
    int i = 0;
    int B[32];
    while (num > 0)
    {
        B[i] = num % 2;
        num = num / 2;
        i++;
    }
    return &(B[0]);
} */

/* This function checks the number of on bits - in identical indexes in 2 unsigned long numbers */
/* int checkBitsNumber(unsigned long x, unsigned long y)
{

} */

int main()
{

    unsigned long x, y;
    int bitsNumber; /* (unsigned long is 32 bits so int) */

    printf("Enter number x: ");
    scanf("%lu", &x);

    printf("Enter number y: ");
    scanf("%lu", &y);

    printf("\nThe input is: \nx: %lu, y: %lu\n", x, y);

    int xBits[32];
    printf("A\n");
    int yBits[32];
    printf("B\n");
    int i = 0;

    while (x > 0)
    {
        xBits[i] = x % 2;
        printf("xBits[%d]: %d ", i, xBits[i]);
        x = x / 2; /* we will have 32 times of /2 (32 bits = 2^32 options) */
        printf("x: %lu \n", x);

        i++;
    }

    printf("B\n");

    i = 0;

    while (y > 0)
    {
        yBits[i] = y % 2;
        printf("yBits[%d] %d ", i, yBits[i]);
        y = y / 2; /* we will have 32 times of /2 (32 bits = 2^32 options) */
        printf("y: %lu \n", x);
        i++;
    }

    printf("C\n");

    printf("\nBinary for x: ");
    for (i = 0; i < 32; i++)
    {
        printf("%d ", xBits[i]);
    }

    printf("\nBinary for y: ");
    for (i = 0; i < 32; i++)
    {
        printf("%d ", yBits[i]);
    }

    return 0;
}