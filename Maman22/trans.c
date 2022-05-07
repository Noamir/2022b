#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

int toStructForTrans(mat_t *all[], char *c, trans_mat_t *ptrStruct)
{
    int idx;

    idx = whichMat(c);
    printf("mat: %d\n", idx);
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

    if (strncmp(c, ",", strlen(",")) == 0)
        return S_FAIL_MULTIPLE_COMMAS;

    /* End of validation */

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

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

int trans_mat(mat_t *mat, mat_t *result)
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
    return S_SUCCESS;
}

int handleTrans(mat_t *all[], char *c)
{
    int status;
    trans_mat_t *my_mat = calloc(1, sizeof(trans_mat_t));

    status = toStructForTrans(all, c, my_mat);

    printf("\ntoStructForTrans status: %d\n", status);

    if (status != S_SUCCESS)
        return status;

    status = trans_mat(my_mat->mat, my_mat->result);

    return status;
}