#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
int validateMat(int matIdx);
int validateCommas(char *command);
int validateNull(char *command);

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

void sub_mat(mat_t *sub1, mat_t *sub2, mat_t *result)
{
    int i, j;

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
            result->matrix[i][j] = sub1->matrix[i][j] - sub2->matrix[i][j];
    }

    print_mat(result);
}

int handleSub(mat_t *all[], char *c)
{
    int status;
    sub_mat_t *my_mat = calloc(1, sizeof(sub_mat_t));
    status = toStructForSub(all, c, my_mat);

    if (status != S_SUCCESS)
        return status;

    sub_mat(my_mat->sub1, my_mat->sub2, my_mat->result);

    return status;
}