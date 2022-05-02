#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

int toStructForSub(mat_t *all[], char *c, sub_mat_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *mat_name;
    int idx;

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    printf("sub1: %s\n", mat_name);

    idx = whichMat(mat_name);

    ptrStruct->sub1 = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    printf("sub2: %s\n", mat_name);

    idx = whichMat(mat_name);

    ptrStruct->sub2 = all[idx];

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    printf("result: %s\n", mat_name);

    idx = whichMat(mat_name);

    ptrStruct->result = all[idx];

    free(tmp);

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

    status = sub_mat(my_mat->sub1, my_mat->sub2, my_mat->result);

    return status;
}