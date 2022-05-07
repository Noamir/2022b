#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
double whichNumber(char *num_str);

int toStructForMulScalar(mat_t *all[], char *c, mul_scalar_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *scalar_str, *end;
    int idx;
    double scalar;

    idx = whichMat(c);

    printf("mat: %d\n", idx);
    printf("currenct command: %s\n", c);

    /* Validations */

    if (idx == MAT_NULL)
    {
        return S_FAIL_MISSING_ARGS;
    }

    if (idx == MAT_UNDEFINED)
    {
        return S_FAIL_NO_MAT;
    }

    if (strncmp(c, ",", strlen(",")) != 0)
        return S_FAIL_MISSING_COMMA;

    memmove(c, c + 1 * sizeof(char), strlen(c)); /* remove the comma */
    printf("currenct command: %s\n", c);

    if (strncmp(c, ",", strlen(",")) == 0)
        return S_FAIL_MULTIPLE_COMMAS;

    /* End of validation */

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    strcpy(tmp, c);

    scalar_str = strtok(tmp, ",");

    scalar = strtod(scalar_str, &end);
    printf("number: %f\n", scalar);
    printf("end: %s\n", end);

    if (strcmp(end, "\0") != 0)
    {
        return S_FAIL_NOT_A_REAL_NUMBER;
    }

    ptrStruct->scalar = scalar;

    memmove(c, c + strlen(scalar_str), strlen(c));

    printf("current command: %s\n", c);

    if (strncmp(c, ",", strlen(",")) != 0)
        return S_FAIL_MISSING_COMMA;

    memmove(c, c + 1 * sizeof(char), strlen(c)); /* remove the comma */
    printf("currenct command: %s\n", c);

    if (strncmp(c, ",", strlen(",")) == 0)
        return S_FAIL_MULTIPLE_COMMAS;

    idx = whichMat(c);

    printf("current command: %s\n", c);

    /* Validations */

    if (idx == MAT_NULL)
    {
        return S_FAIL_MISSING_ARGS;
    }

    if (idx == MAT_UNDEFINED)
    {
        return S_FAIL_NO_MAT;
    }

    if (strcmp(c, "\0") != 0)
    {
        return S_FAIL_EXTRA_TEXT;
    }

    /* End of validation */

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

    if (status != S_SUCCESS)
        return status;

    status = mul_scalar(my_mat->mat, my_mat->scalar, my_mat->result);

    return status;
}