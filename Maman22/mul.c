#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
int validateMat(int matIdx);
int validateCommas(char *command);
int validateNull(char *command);

int toStructForMul(mat_t *all[], char *c, mul_mat_t *ptrStruct)
{
    int idx, status;

    idx = whichMat(c);
    printf("mul1: %d\n", idx);
    printf("currenct command: %s\n", c);

    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mul1 = all[idx];

    idx = whichMat(c);
    printf("mul2: %d\n", idx);
    printf("currenct command: %s\n", c);

    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mul2 = all[idx];

    idx = whichMat(c);
    printf("result: %d\n", idx);
    printf("currenct command: %s\n", c);

    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateNull(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->result = all[idx];

    return status;
}

void mul_mat(mat_t *mul1, mat_t *mul2, mat_t *result)
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

}

int handleMul(mat_t *all[], char *c)
{
    int status;
    mul_mat_t *my_mat = calloc(1, sizeof(mul_mat_t));

    status = toStructForMul(all, c, my_mat);

    printf("\ntoStructForMul status: %d\n", status);

    if (status != S_SUCCESS)
        return status;

    mul_mat(my_mat->mul1, my_mat->mul2, my_mat->result);

    return status;
}