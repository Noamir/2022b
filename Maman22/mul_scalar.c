#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
double whichNumber(char *num_str);
int validateMat(int matIdx);
int validateCommas(char *command);
int validateNull(char *command);

int toStructForMulScalar(mat_t *all[], char *c, mul_scalar_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *scalar_str, *end;
    int idx, status;
    double scalar;

    idx = whichMat(c);

    printf("mat: %d\n", idx);
    printf("currenct command: %s\n", c);

    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    strcpy(tmp, c);

    scalar_str = strtok(tmp, ",");

    scalar = strtod(scalar_str, &end);

    printf("number: %f\n", scalar);
    printf("end: %s\n", end);

    if (strcmp(end, "\0") != 0)
    {
        return S_FAIL_NOT_A_SCALAR;
    }

    ptrStruct->scalar = scalar;

    memmove(c, c + strlen(scalar_str), strlen(c));

    printf("current command: %s\n", c);

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    idx = whichMat(c);

    printf("current command: %s\n", c);

    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateNull(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->result = all[idx];

    free(tmp);

    return status;
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

    if (status != S_SUCCESS)
        return status;

    status = mul_scalar(my_mat->mat, my_mat->scalar, my_mat->result);

    return status;
}