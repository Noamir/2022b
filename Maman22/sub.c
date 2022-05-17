#include "handlers.h"

struct sub_mat_def
{
    mat_t *sub1;
    mat_t *sub2;
    mat_t *result;
};

/* toStructForSub: Get sub_mat command string, validate its components, adapt it to sub_mat struct */
int toStructForSub(mat_t *all[], char *c, sub_mat_t *ptrStruct)
{
    int idx, status;
    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->sub1 = all[idx];

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->sub2 = all[idx];

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

/* subMat: Get 3 mats, sub mat sub2 from mat sub1 and insert result to mat result */
void subMat(mat_t *sub1, mat_t *sub2, mat_t *result)
{
    int i, j;
    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
            result->matrix[i][j] = sub1->matrix[i][j] - sub2->matrix[i][j];
    }
    printMat(result);
}

/* handleSub: Handle sub_mat process - from string input to execution */
int handleSub(mat_t *all[], char *c)
{
    int status;
    sub_mat_t *my_mat = calloc(1, sizeof(sub_mat_t));
    status = toStructForSub(all, c, my_mat);
    if (status != S_SUCCESS)
        return status;

    subMat(my_mat->sub1, my_mat->sub2, my_mat->result);
    free(my_mat);
    return status;
}