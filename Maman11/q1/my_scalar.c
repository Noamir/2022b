#include <stdio.h>
#define MAX_SIZE 100000 /* max size of vector */

/* scalar_product: get 2 vectors and their size, return the vectors scalar product */
int scalar_product(int size, int vec1[], int vec2[])
{
    int i, scalar_product_res = 0;

    for (i = 0; i < size; i++)
    {
        scalar_product_res += vec1[i] * vec2[i];
    }

    return scalar_product_res;
}

/* get size for 2 vectors and 2 vectors from stdin, print the vectors scalar product */
int main()
{
    int size, scalar_product_res, i;

    int vec1[MAX_SIZE];
    int vec2[MAX_SIZE];

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

    scalar_product_res = scalar_product(size, vec1, vec2);
    printf("\nThe scalar product of the vectors is: %d \n", scalar_product_res);

    return 0;
}