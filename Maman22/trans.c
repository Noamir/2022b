#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

int toStructForTrans(mat_t *all[], char *c, trans_mat_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *mat_name;
    int idx;

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    idx = whichMat(mat_name);

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    idx = whichMat(mat_name);

    ptrStruct->result = all[idx];

    free(tmp);

    return S_SUCCESS;
}

int trans_mat(mat_t *mat, mat_t *result)
{
    int i, j, k;

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

    status = trans_mat(my_mat->mat, my_mat->result);

    return status;
}