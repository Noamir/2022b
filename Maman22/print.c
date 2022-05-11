#include "mat.h"

int whichMat(char *c);
int validateMat(int matIdx);
int validateNull(char *command);

int toStructForPrint(mat_t *all[], char *c, print_mat_t *ptrStruct)
{
    int idx, status;

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateNull(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mat = all[idx];

    return status;
}

void print_mat(mat_t *m)
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
}

int handlePrint(mat_t *all[], char *c)
{
    int status;
    
    print_mat_t *my_mat = calloc(1, sizeof(print_mat_t));
    status = toStructForPrint(all, c, my_mat);

    if (status != S_SUCCESS)
        return status;

    print_mat(my_mat->mat);

    return status;
}
