#include <stdio.h>

int get_scalar_product();

/* call get_scalar_product function to handle inputs, outputs and calculation of 2 vectors scalar product. Print the scalar product */
int main()
{
    int scalar_product;
    scalar_product = get_scalar_product();
    printf("\nThe scalar product of the vectors is: %d \n", scalar_product);

    return 0;
}