#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

int toStructForAdd(mat_t *all[], char *c, add_mat_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *mat_name;
    int idx;

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    printf("add1: %s\n", mat_name);

    idx = whichMat(mat_name);

    ptrStruct->add1 = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    printf("add2: %s\n", mat_name);

    idx = whichMat(mat_name);

    ptrStruct->add2 = all[idx];

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    printf("add3: %s\n", mat_name);

    idx = whichMat(mat_name);

    ptrStruct->result = all[idx];

    free(tmp);

    return S_SUCCESS;
}

int add_mat(mat_t *add1, mat_t *add2, mat_t *result)
{
    int i,j;

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

    status = add_mat(my_mat->add1, my_mat->add2, my_mat->result);

    return status;
}