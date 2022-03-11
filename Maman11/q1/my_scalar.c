#include <stdio.h>

int product_scalar(int size, int vec1[], int vec2[])
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

    printf("Enter vectors size: ");
    scanf("%d", &size);

    int vec1[size];
    int vec2[size];

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

    scalarProduct = product_scalar(size, vec1, vec2);
    printf("\nThe scalar product of the vectors is: %d \n", scalarProduct);

    return 0;
}