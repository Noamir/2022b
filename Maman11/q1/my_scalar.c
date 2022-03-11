#include <stdio.h>
#define MAX_SIZE  100000 /* max size of vector */

/* Function that calculates 2 vectors of size <size> scalar product */
int getScalarProduct(int size, int vec1[], int vec2[])
{
    int i, scalarProduct = 0;

    for (i = 0; i < size; i++)
    {
        scalarProduct += vec1[i] * vec2[i];
    }

    return scalarProduct;
}

int main()
{
    int size, scalarProduct, i;

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

    scalarProduct = getScalarProduct(size, vec1, vec2);
    printf("\nThe scalar product of the vectors is: %d \n", scalarProduct);

    return 0;
}