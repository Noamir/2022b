/* scalar_product: get 2 vectors and their size, calculate and return the vectors scalar product */
int scalar_product(int size, int vec1[], int vec2[])
{
    int i, scalar_product_res = 0;

    for (i = 0; i < size; i++)
    {
        scalar_product_res += vec1[i] * vec2[i];
    }

    return scalar_product_res;
}