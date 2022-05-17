#include "handlers.h"

struct mul_mat_def
{
    mat_t *mul1;
    mat_t *mul2;
    mat_t *result;
};

/* toStructForMul: Get mul_mat command string, validate its components, adapt it to mul_mat struct */
int toStructForMul(mat_t *all[], char *c, mul_mat_t *ptrStruct)
{
    int idx, status;
    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mul1 = all[idx];

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mul2 = all[idx];

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateNull(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->result = all[idx];

    return status;
}

/* mulMat: Get 3 mats, mul mat mul1 in mat mul2 and insert result to mat result */
void mulMat(mat_t *mul1, mat_t *mul2, mat_t *result)
{
    int i, j, k;
    mat_t *tmp = calloc(1, sizeof(mat_t));
    tmp->size = MAT_SIZE;

    for (i = 0; i < mul1->size; i++)
    {
        for (j = 0; j < mul2->size; j++)
        {
            for (k = 0; k < mul2->size; k++)
                tmp->matrix[i][j] += mul1->matrix[i][k] * mul2->matrix[k][j];
        }
    }

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
            result->matrix[i][j] = tmp->matrix[i][j];
    }
    free(tmp);
    print_mat(result);
}

/* handleMul: Handle mul_mat process - from string input to execution */
int handleMul(mat_t *all[], char *c)
{
    int status;
    mul_mat_t *my_mat = calloc(1, sizeof(mul_mat_t));
    status = toStructForMul(all, c, my_mat);
    if (status != S_SUCCESS)
        return status;

    mulMat(my_mat->mul1, my_mat->mul2, my_mat->result);
    return status;
}