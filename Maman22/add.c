#include "handlers.h"

struct add_mat_def
{
    mat_t *add1;
    mat_t *add2;
    mat_t *result;
};

/* toStructForAdd: Get add_mat command string, validate its components, adapt it to add_mat struct */
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

/* addMat: Get 3 mats, add mat add1 to mat add2 and insert result to mat result */
void addMat(mat_t *add1, mat_t *add2, mat_t *result)
{
    int i, j;

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
            result->matrix[i][j] = add1->matrix[i][j] + add2->matrix[i][j];
    }

    print_mat(result);
}

/* handleAdd: Handle add_mat process - from string input to execution */
int handleAdd(mat_t *all[], char *c)
{
    int status;
    add_mat_t *my_mat = calloc(1, sizeof(add_mat_t));
    status = toStructForAdd(all, c, my_mat);
    if (status != S_SUCCESS)
        return status;

    addMat(my_mat->add1, my_mat->add2, my_mat->result);
    return status;
}