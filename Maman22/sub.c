#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

int toStructForSub(mat_t *all[], char *c, sub_mat_t *ptrStruct)
{
    int idx;

    idx = whichMat(c);
    printf("sub1: %d\n", idx);
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

    ptrStruct->sub1 = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    idx = whichMat(c);
    printf("sub2: %d\n", idx);
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

    ptrStruct->sub2 = all[idx];

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

int sub_mat(mat_t *sub1, mat_t *sub2, mat_t *result)
{
    int i, j;

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
        {
            result->matrix[i][j] = sub1->matrix[i][j] - sub2->matrix[i][j];
        }
    }

    print_mat(result);

    return S_SUCCESS;
}

int handleSub(mat_t *all[], char *c)
{
    int status;
    sub_mat_t *my_mat = calloc(1, sizeof(sub_mat_t));

    status = toStructForSub(all, c, my_mat);

    printf("\ntoStructForSub status: %d\n", status);

    if (status != S_SUCCESS)
        return status;

    status = sub_mat(my_mat->sub1, my_mat->sub2, my_mat->result);

    return status;
}