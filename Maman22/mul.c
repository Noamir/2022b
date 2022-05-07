#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

int toStructForMul(mat_t *all[], char *c, mul_mat_t *ptrStruct)
{
   int idx;

    idx = whichMat(c);
    printf("mul1: %d\n", idx);
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

    /* End of validation */

    ptrStruct->mul1 = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    idx = whichMat(c);
    printf("mul2: %d\n", idx);
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

    /* End of validation */

    ptrStruct->mul2 = all[idx];

    idx = whichMat(c);
    printf("result: %d\n", idx);
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

    if (strcmp(c, "\0") != 0)
    {
        return S_FAIL_EXTRA_TEXT;
    }

    /* End of validation */

    ptrStruct->result = all[idx];

    return S_SUCCESS;
}

int mul_mat(mat_t *mul1, mat_t *mul2, mat_t *result)
{
    int i, j, k;

    for (i = 0; i < mul1->size; i++)
    {
        for (j = 0; j < mul2->size; j++)
        {
            result->matrix[i][j] = 0;

            for (k = 0; k < mul2->size; k++)
            {
                result->matrix[i][j] += mul1->matrix[i][k] * mul2->matrix[k][j];
            }
        }
    }

    print_mat(result);
    return S_SUCCESS;
}

int handleMul(mat_t *all[], char *c)
{
    int status;
    mul_mat_t *my_mat = calloc(1, sizeof(mul_mat_t));

    status = toStructForMul(all, c, my_mat);

    printf("\ntoStructForMul status: %d\n", status);

    if (status != S_SUCCESS)
        return status;

    status = mul_mat(my_mat->mul1, my_mat->mul2, my_mat->result);

    return status;
}