#include <stdio.h>
#define UNSIGNED_LONG_BITS 32

/* This function updates bitsArr with unsigned long num binary representation */
void ULToBit(unsigned long num, int *bitsArr)
{
    int i = 0;

    while (num > 0)
    {
        bitsArr[i] = num % 2;
        num = num / 2;
        i++;
    }
}

int main()
{   
    /* variables */
    unsigned long x, y;
    int i, bitsCounter = 0;

    /* initialize bits arrays cells to 0 */
    int xBits[UNSIGNED_LONG_BITS] = {0};
    int yBits[UNSIGNED_LONG_BITS] = {0};


    /* inputs */
    printf("Enter number x: ");
    scanf("%lu", &x);

    printf("Enter number y: ");
    scanf("%lu", &y);

    printf("\nThe input is: \nx: %lu, y: %lu\n", x, y);

    /* update bits arrays cells to the numbers binary representation */
    ULToBit(x, xBits);
    ULToBit(y, yBits);


    /* TODO - delete - just for debug - print numbers binary */
    printf("\nBinary for x: ");
    for (i = UNSIGNED_LONG_BITS-1; i >= 0; i--)
    {
        printf("%d ", xBits[i]);
    }

    printf("\nBinary for y: ");
    for (i = UNSIGNED_LONG_BITS-1; i >= 0; i--)
    {
        printf("%d ", yBits[i]);
    }

    /* count indexes where both numbers have binary value 1 */
    for (i = 0; i < UNSIGNED_LONG_BITS; i++)
    {
        if (xBits[i] && yBits[i])
        {
            bitsCounter++;
        }
    }

    printf("\nNumber of 'on' (=1) bits in both numbers: %d\n", bitsCounter);

    return 0;
}