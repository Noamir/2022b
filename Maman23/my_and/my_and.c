#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ALL_BITS_ON 4294967295

/* dec_to_hex:
Gets a decimal number and converts it to its hexadecimal representation
Returns a pointer to the hexadecimal number created
*/
char *dec_to_hex(int decimal)
{
    int temp;
    int i = 0, j = 0;
    char *hexadecimalNumber = (char *)malloc(8 * sizeof(char)); /* make sure the size is OK? */

    while (decimal != 0)
    {
        temp = decimal % 16;
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexadecimalNumber[i++] = temp;
        decimal = decimal / 16;
    }

    /* reverse hexadecimalNumber array */
    for (j = 0; j < i; j++)
    {
        temp = hexadecimalNumber[j];
        hexadecimalNumber[j] = hexadecimalNumber[i-1];
        hexadecimalNumber[i-1] = temp;
        i--;
    }

    return hexadecimalNumber;
}

/** get_bits_and:
Gets count param which indicates how many unsigned int parameters this function will get.
The function can get unlimited unsigned int parameters.
The function returns the result of 'and' - '&' between all parameters bits. (exclusing the count parameter)
**/
int get_bits_and(unsigned int count, ...)
{
    va_list args;
    int i;
    unsigned int curr, bits_and = ALL_BITS_ON; /* initial bits_and value is the max unsigned int value - so it won't affect the result */

    va_start(args, count);

    printf("The parameters seperated by space are:");
    for (i = 0; i < count; i++)
    {
        curr = va_arg(args, unsigned int);  /* get the current parameter */
        printf(" %d ", curr);               /* print the current parameter */
        bits_and = bits_and & curr;         /* calculate the & result with the current parameter */
    }
    printf("\n");

    va_end(args);
    return bits_and;
}

int main(void)
{
    unsigned int bits_and_result;
    char *hexa;

    printf("======== RUN 1 ========\n\n");
    bits_and_result = get_bits_and(3, 5, 7, 61);
    printf("bits_and_result Decimal: %d\n", bits_and_result);
    hexa = dec_to_hex(bits_and_result);
    printf("bits_and_result Hexadecimal: %s\n", hexa);
    printf("\n=======================\n\n");


    printf("======== RUN 2 ========\n\n");
    bits_and_result = get_bits_and(5, 15, 687, 831, 349535, 95);
    printf("bits_and_result Decimal: %d\n", bits_and_result);
    hexa = dec_to_hex(bits_and_result);
    printf("bits_and_result Hexadecimal: %s\n", hexa);
    printf("\n=======================\n\n");


    printf("======== RUN 3 ========\n\n");
    bits_and_result = get_bits_and(10, 938, 106, 170, 362, 746, 3818, 2794, 2730, 31402, 55978);
    printf("bits_and_result Decimal: %d\n", bits_and_result);
    hexa = dec_to_hex(bits_and_result);
    printf("bits_and_result Hexadecimal: %s\n", hexa);
    printf("\n=======================\n\n");


    printf("======== RUN 4 ========\n\n");
    bits_and_result = get_bits_and(15, 262143, 8388607, 8126463, 6029291, 3932137, 2359264, 3407840, 3932128, 8126432, 8126433, 6029283, 5898179, 5799683, 5930771, 5996288);
    printf("bits_and_result Decimal: %d\n", bits_and_result);
    hexa = dec_to_hex(bits_and_result);
    printf("bits_and_result Hexadecimal: %s\n", hexa);
    printf("\n=======================\n\n");

    free(hexa);
    return 0;
}