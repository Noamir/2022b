#include "mat.h"

int whichMat(char *c);

int toStructForPrint(mat_t *all[], char *c, print_mat_t *ptrStruct)
{
    int idx;

    idx = whichMat(c);

    ptrStruct->mat = all[idx];
    
    return S_SUCCESS;
}

int print_mat(mat_t *m)
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

    return S_SUCCESS;
}

int handlePrint(mat_t *all[], char *c)
{
    int status;
    print_mat_t *my_mat = calloc(1, sizeof(print_mat_t));

    status = toStructForPrint(all, c, my_mat);

    printf("\ntoStructForPrint status: %d\n", status);

    status = print_mat(my_mat->mat);

    return status;
}
