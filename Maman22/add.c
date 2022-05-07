#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

int toStructForAdd(mat_t *all[], char *c, add_mat_t *ptrStruct)
{
    int idx;

    idx = whichMat(c);
    printf("add1: %d\n", idx);
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

    ptrStruct->add1 = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    idx = whichMat(c);
    printf("add2: %d\n", idx);
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

    ptrStruct->add2 = all[idx];

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

int add_mat(mat_t *add1, mat_t *add2, mat_t *result)
{
    int i, j;

    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
        {
            result->matrix[i][j] = add1->matrix[i][j] + add2->matrix[i][j];
        }
    }

    print_mat(result);

    return S_SUCCESS;
}

int handleAdd(mat_t *all[], char *c)
{
    int status;
    add_mat_t *my_mat = calloc(1, sizeof(add_mat_t));

    status = toStructForAdd(all, c, my_mat);

    printf("\ntoStructForAdd status: %d\n", status);

    if (status != S_SUCCESS)
        return status;

    status = add_mat(my_mat->add1, my_mat->add2, my_mat->result);

    return status;
}