/* This program gets size for 2 vectors and the 2 vectors integers, and prints the vectors scalar product */

#include <stdio.h>
#define MAX_SIZE 1000 /* max size of vector */

int scalar_product(int size, int vec1[], int vec2[]);

int main()
{
    int size, i, scalar_product_res;
    int vec1[MAX_SIZE];
    int vec2[MAX_SIZE];

    /* inputs: get vectors size and vectors integers from stdin */
    printf("Enter vectors size (max valid size is %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("\nEnter %d integers for vector number 1: ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &vec1[i]);
    }

    printf("\nEnter %d integers for vector number 2: ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &vec2[i]);
    }

    /* send inputs to scalar_product function - to calculate vectors scalar product */
    scalar_product_res = scalar_product(size, vec1, vec2);

    printf("\nThe scalar product of the vectors is: %d \n", scalar_product_res);

    return 0;
}