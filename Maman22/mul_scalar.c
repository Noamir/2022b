#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
double whichNumber(char *num_str);

int toStructForMulScalar(mat_t *all[], char *c, mul_scalar_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *mat_name, *scalar_str;
    int idx, scalar;

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    idx = whichMat(mat_name);

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    scalar_str = strtok(tmp, ",");

    scalar = whichNumber(scalar_str);

    ptrStruct->scalar = scalar;

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    idx = whichMat(mat_name);

    ptrStruct->result = all[idx];

    free(tmp);

    return S_SUCCESS;
}

int mul_scalar(mat_t *mat, double scalar, mat_t *result)
{
    int i, j;

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
        {
            result->matrix[i][j] = mat->matrix[i][j] * scalar;
        }
    }

    print_mat(result);
    return S_SUCCESS;
}

int handleMulScalar(mat_t *all[], char *c)
{
    int status;
    mul_scalar_t *my_mat = calloc(1, sizeof(mul_scalar_t));

    status = toStructForMulScalar(all, c, my_mat);

    printf("\ntoStructForMulScalar status: %d\n", status);

    status = mul_scalar(my_mat->mat, my_mat->scalar, my_mat->result);

    return status;
}