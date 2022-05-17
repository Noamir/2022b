#include "handlers.h"

struct trans_mat_def
{
    mat_t *mat;
    mat_t *result;
};

/* toStructForTrans: Get trans_mat command string, validate its components, adapt it to trans_mat struct */
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

/* subMat: Get 2 mats, transfer mat and insert result to mat result */
void transMat(mat_t *mat, mat_t *result)
{
    int i, j;
    mat_t *tmp = calloc(1, sizeof(mat_t));
    tmp->size = MAT_SIZE;

    for (i = 0; i < tmp->size; i++)
    {
        for (j = 0; j < tmp->size; j++)
            tmp->matrix[i][j] = mat->matrix[j][i];
    }

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
            result->matrix[i][j] = tmp->matrix[i][j];
    }
    free(tmp);
    printMat(result);
}

/* handleTrans: Handle trans_mat process - from string input to execution */
int handleTrans(mat_t *all[], char *c)
{
    int status;
    trans_mat_t *my_mat = calloc(1, sizeof(trans_mat_t));
    status = toStructForTrans(all, c, my_mat);
    if (status != S_SUCCESS)
        return status;

    transMat(my_mat->mat, my_mat->result);
    return status;
}