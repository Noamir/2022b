#include "mat.h"

int toStructForPrint(mat_t *all[], char *c, print_mat_t *ptrStruct)
{
    int idx;

    if (strncmp(c, "MAT_A", strlen("MAT_A")) == 0)
    {
        idx = E_MAT_A;
    }
    else if (strncmp(c, "MAT_B", strlen("MAT_B")) == 0)
    {
        idx = E_MAT_B;
    }
    else if (strncmp(c, "MAT_C", strlen("MAT_C")) == 0)
    {
        idx = E_MAT_C;
    }
    else if (strncmp(c, "MAT_D", strlen("MAT_D")) == 0)
    {
        idx = E_MAT_D;
    }
    else if (strncmp(c, "MAT_E", strlen("MAT_E")) == 0)
    {
        idx = E_MAT_E;
    }
    else if (strncmp(c, "MAT_F", strlen("MAT_F")) == 0)
    {
        idx = E_MAT_F;
    }
    else
    {
        return S_FAIL_WRONG_PARAMS;
    }

    ptrStruct->mat = all[idx];
    return S_SUCCESS;
}

void doPrint(mat_t *m)
{
    int i = 0;
    int j = 0;

    printf("\n\n");
    for (i = 0; i < m->size * m->size; i++, j++)
    {

        if (j == m->size)
        {
            printf("\n");
            j = 0;
        }
        printf("%7.2f  ", m->matrix[i]);
    }
    printf("\n\n");
}

int handlePrint(mat_t *all[], char *c)
{
    int status;
    print_mat_t *my_mat = calloc(1, sizeof(print_mat_t));

    status = toStructForPrint(all, c, my_mat);

    printf("\ntoStructForPrint status: %d\n", status);

    doPrint(my_mat->mat);

    return S_SUCCESS;
}
