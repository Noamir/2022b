#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *dec_to_hex(int decimal)
{
    int temp;
    int i = 0;
    char *hexadecimalNumber = (char *)malloc(1000 * sizeof(char));
    ;

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
    unsigned int bits_and = 4294967295, next; /* initial bits_and value is the max unsigned int value - so it won't affect the result */

    va_start(args, count);

    for (i = 0; i < count; i++)
    {
        next = va_arg(args, unsigned int);
        bits_and = bits_and & next;
        /*         printf("next: %d\n", next);
                printf("bits_and: %d\n", bits_and); */
    }

    va_end(args);
    return bits_and;
}

int main(void)
{
    unsigned int bits_and_result;
    char *hexa;

    /* TODO: hexa - print array from end to start */
    /* TODO: print all sent parameters */

    bits_and_result = get_bits_and(3, 5, 7, 61);
    printf("\n\nbits and result 1 decimal: %d\n", bits_and_result);
    hexa = dec_to_hex(bits_and_result);
    printf("bits and result 1 hexa decimal: %s\n", hexa);


    bits_and_result = get_bits_and(5, 15, 687, 831, 349535, 95);
    printf("\n\nbits and result 2 decimal: %d\n", bits_and_result);
    hexa = dec_to_hex(bits_and_result);
    printf("bits and result 2 hexa decimal: %s\n", hexa);


    bits_and_result = get_bits_and(10, 938, 106, 170, 362, 746, 3818, 2794, 2730, 31402, 55978);
    printf("\n\nbits and result 3 decimal: %d\n", bits_and_result);
    hexa = dec_to_hex(bits_and_result);
    printf("bits and result 3 hexa decimal: %s\n", hexa);


    bits_and_result = get_bits_and(15, 262143, 8388607, 8126463, 6029291, 3932137, 2359264, 3407840, 3932128, 8126432, 8126433, 6029283, 5898179, 5799683, 5930771, 5996288);
    printf("\n\nbits and result 4 decimal: %d\n", bits_and_result);
    hexa = dec_to_hex(bits_and_result);
    printf("bits and result 4 hexa decimal: %s\n", hexa);

    free(hexa);
    return 0;
}