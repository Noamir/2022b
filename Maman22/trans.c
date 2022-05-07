#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
int validateMat(int matIdx);
int validateCommas(char *command);
int validateNull(char *command);

int toStructForTrans(mat_t *all[], char *c, trans_mat_t *ptrStruct)
{
    int idx, status;

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

void trans_mat(mat_t *mat, mat_t *result)
{
    int i, j;

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
        {
            result->matrix[i][j] = mat->matrix[j][i];
        }
    }

    print_mat(result);
}

int handleTrans(mat_t *all[], char *c)
{
    int status;
    trans_mat_t *my_mat = calloc(1, sizeof(trans_mat_t));

    status = toStructForTrans(all, c, my_mat);

    printf("\ntoStructForTrans status: %d\n", status);

    if (status != S_SUCCESS)
        return status;

    trans_mat(my_mat->mat, my_mat->result);

    return status;
}