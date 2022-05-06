#include "mat.h"

int whichMat(char *c);
int validatePrint(char *command, int argTypes[], int argsNum);

int toStructForPrint(mat_t *all[], char *c, print_mat_t *ptrStruct)
{
    int idx;

    idx = whichMat(c);

    ptrStruct->mat = all[idx];

    return S_SUCCESS;
}

int print_mat(mat_t *m)
{
    int i,j;

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

   /*  status = validatePrint(c, my_mat->args, 1); */

    status = toStructForPrint(all, c, my_mat);

    printf("\ntoStructForPrint status: %d\n", status);

    status = print_mat(my_mat->mat);

    return status;
}
