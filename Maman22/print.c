#include "mat.h"

int whichMat(char *c);
int validate(char *command, int argTypes[]);

int toStructForPrint(mat_t *all[], char *c, print_mat_t *ptrStruct)
{
    int idx;

    idx = whichMat(c);
    
    printf("toStruct: current command: %s\n", c);
    printf("toStruct: current idx: %d\n", idx);

    /* Validations */

    if(idx == MAT_NULL)
    {
        printf("MAT is NULL\n");
        return S_FAIL_MISSING_ARGS;
    }

    if (idx == MAT_UNDEFINED)
    {
        printf("MAT is undefined\n");
        return S_FAIL_NO_MAT;
    }

    if (strcmp(c, "\0") != 0)
    {
        printf("Extra text after args\n");
        return S_FAIL_EXTRA_TEXT;
    }

    ptrStruct->mat = all[idx];

    return S_SUCCESS;
}

int print_mat(mat_t *m)
{
    int i, j;

    printf("\n\n");
    for (i = 0; i < m->size; i++, j++)
    {
        for (j = 0; j < m->size; j++)
        {
            printf("%7.2f  ", m->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return S_SUCCESS;
}

int handlePrint(mat_t *all[], char *c)
{
    int status;
    print_mat_t *my_mat = calloc(1, sizeof(print_mat_t));

    my_mat->args[0] = A_MAT;

    status = toStructForPrint(all, c, my_mat);
    printf("\ntoStructForPrint status: %d\n", status);

    if (status != S_SUCCESS)
        return status;

    status = print_mat(my_mat->mat);

    return status;
}
