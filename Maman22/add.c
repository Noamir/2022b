#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
int validateMat(int matIdx);
int validateCommas(char *command);
int validateNull(char *command);

int toStructForAdd(mat_t *all[], char *c, add_mat_t *ptrStruct)
{
    int idx, status;

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->add1 = all[idx];

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->add2 = all[idx];

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

void add_mat(mat_t *add1, mat_t *add2, mat_t *result)
{
    int i, j;

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
            result->matrix[i][j] = add1->matrix[i][j] + add2->matrix[i][j];
    }

    print_mat(result);
}

int handleAdd(mat_t *all[], char *c)
{
    int status;

    add_mat_t *my_mat = calloc(1, sizeof(add_mat_t));
    status = toStructForAdd(all, c, my_mat);
    if (status != S_SUCCESS)
        return status;

    add_mat(my_mat->add1, my_mat->add2, my_mat->result);

    return status;
}