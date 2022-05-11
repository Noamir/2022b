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
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mat = all[idx];

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

void trans_mat(mat_t *mat, mat_t *result)
{
    int i, j;
    mat_t *tmp = calloc(1, sizeof(mat_t));
    tmp->size = MAT_SIZE;

    for (i = 0; i < tmp->size; i++)
    {
        for (j = 0; j < tmp->size; j++)
            tmp->matrix[i][j] = mat->matrix[j][i];
    }
    print_mat(tmp);

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
            result->matrix[i][j] = tmp->matrix[i][j];
    }
    free(tmp);
    print_mat(result);
}

int handleTrans(mat_t *all[], char *c)
{
    int status;
    trans_mat_t *my_mat = calloc(1, sizeof(trans_mat_t));
    status = toStructForTrans(all, c, my_mat);

    if (status != S_SUCCESS)
        return status;

    trans_mat(my_mat->mat, my_mat->result);

    return status;
}