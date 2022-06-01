#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/** get_bits_and:
Gets count parameter which indicates how many unsigned int parameters this function will get.
The function can get dynamic unlimited unsigned int parameters.
The function returns the result of 'and' - '&' between all parameters bits. (exclusing the count parameter)
**/
int get_bits_and(unsigned int count, ...)
{
    va_list args;
    int i;
    unsigned int curr, bits_and = ~0;       /* initial bits_and value is the value of all on bits - so it won't affect the result */
    va_start(args, count);
    for (i = 0; i < count; i++)
    {
        curr = va_arg(args, unsigned int);  /* get the current parameter */
        bits_and = bits_and & curr;         /* calculate the & result with the current parameter */
    }

    va_end(args);
    return bits_and;
}

/** print_decimal:
Gets count parameter which indicates how many unsigned int parameters this function will get.
The function can get dynamic unlimited unsigned int parameters.
The function prints all parameters in decimal base, seperated by commas. (exclusing the count parameter)
 **/
void print_decimal(unsigned int count, ...)
{
    va_list args;
    int i;
    unsigned int curr;

    va_start(args, count);
    printf("The parameters in Decimal base:\n");
    for (i = 0; i < count; i++)
    {
        curr = va_arg(args, unsigned int);  /* get the current parameter */
        if (i == count - 1)
            printf("%u", curr);             /* print the current parameter without a following comma */
        else
            printf("%u, ", curr);           /* print the current parameter with a following comma */
    }
    
    printf("\n\n");
    va_end(args);
}

/** print_hexadecimal:
Gets count parameter which indicates how many unsigned int parameters this function will get.
The function can get dynamic unlimited unsigned int parameters.
The function prints all parameters in hexadecimal base, seperated by commas. (exclusing the count parameter)
 **/
void print_hexadecimal(unsigned int count, ...)
{
    va_list args;
    int i;
    unsigned int curr;

    va_start(args, count);
    printf("The parameters in Hexadecimal base:\n");
    for (i = 0; i < count; i++)
    {
        curr = va_arg(args, unsigned int);  /* get the current parameter */
        if (i == count - 1)
            printf("%X", curr);             /* print the current parameter without a following comma */
        else
            printf("%X, ", curr);           /* print the current parameter with a following comma */
    }
    
    printf("\n\n");
    va_end(args);
}

/** This program calls get_bits_and function 4 times. Each time with a different number of parameters.
 The program prints to stdout:
 1. All parameters sent to get_bits_and function - dynamic unlimited number of parameters - in Decimal base
 2. All parameters sent to get_bits_and function - dynamic unlimited number of parameters - in Hexadecimal base
 2. bits_and_result in Decimal base
 3. bits_and_result in Hexadecimal base
**/
int main(void)
{
    unsigned int bits_and_result;

    printf("======== RUN 1 ========\n\n");
    print_decimal(3, 5, 7, 61);
    print_hexadecimal(3, 5, 7, 61);
    bits_and_result = get_bits_and(3, 5, 7, 61);
    printf("bits_and_result Decimal: %u\n", bits_and_result);
    printf("bits_and_result Hexadecimal: %X\n", bits_and_result);
    printf("\n=======================\n\n");

    printf("======== RUN 2 ========\n\n");
    print_decimal(5, 15, 687, 831, 349535, 95);
    print_hexadecimal(5, 15, 687, 831, 349535, 95);
    bits_and_result = get_bits_and(5, 15, 687, 831, 349535, 95);
    printf("bits_and_result Decimal: %u\n", bits_and_result);
    printf("bits_and_result Hexadecimal: %X\n", bits_and_result);
    printf("\n=======================\n\n");

    printf("======== RUN 3 ========\n\n");
    print_decimal(10, 938, 106, 170, 362, 746, 3818, 2794, 2730, 31402, 55978);
    print_hexadecimal(10, 938, 106, 170, 362, 746, 3818, 2794, 2730, 31402, 55978);
    bits_and_result = get_bits_and(10, 938, 106, 170, 362, 746, 3818, 2794, 2730, 31402, 55978);
    printf("bits_and_result Decimal: %u\n", bits_and_result);
    printf("bits_and_result Hexadecimal: %X\n", bits_and_result);
    printf("\n=======================\n\n");

    printf("======== RUN 4 ========\n\n");
    print_decimal(15, 262143, 8388607, 8126463, 6029291, 3932137, 2359264, 3407840, 3932128, 8126432, 8126433, 6029283, 5898179, 5799683, 5930771, 5996288);
    print_hexadecimal(15, 262143, 8388607, 8126463, 6029291, 3932137, 2359264, 3407840, 3932128, 8126432, 8126433, 6029283, 5898179, 5799683, 5930771, 5996288);
    bits_and_result = get_bits_and(15, 262143, 8388607, 8126463, 6029291, 3932137, 2359264, 3407840, 3932128, 8126432, 8126433, 6029283, 5898179, 5799683, 5930771, 5996288);
    printf("bits_and_result Decimal: %u\n", bits_and_result);
    printf("bits_and_result Hexadecimal: %X\n", bits_and_result);
    printf("\n=======================\n\n");


    /* Extra test runs */
    printf("======== RUN 5 ========\n\n");
    print_decimal(0);
    print_hexadecimal(0);
    bits_and_result = get_bits_and(0);
    printf("bits_and_result Decimal: %u\n", bits_and_result);
    printf("bits_and_result Hexadecimal: %X\n", bits_and_result);
    printf("\n=======================\n\n");

    printf("======== RUN 6 ========\n\n");
    print_decimal(3, 2, 6, 10);
    print_hexadecimal(3, 2, 6, 10);
    bits_and_result = get_bits_and(3, 2, 6, 10);
    printf("bits_and_result Decimal: %u\n", bits_and_result);
    printf("bits_and_result Hexadecimal: %X\n", bits_and_result);
    printf("\n=======================\n\n");

    return 0;
}