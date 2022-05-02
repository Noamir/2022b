#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

int toStructForMul(mat_t *all[], char *c, mul_mat_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *mat_name;
    int idx;

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    idx = whichMat(mat_name);

    ptrStruct->mul1 = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    idx = whichMat(mat_name);

    ptrStruct->mul2 = all[idx];

    memmove(c, c + strlen(mat_name) + 1, strlen(c));

    strcpy(tmp, c);

    mat_name = strtok(tmp, ",");

    idx = whichMat(mat_name);

    ptrStruct->result = all[idx];

    free(tmp);

    return S_SUCCESS;
}

int mul_mat(mat_t *mul1, mat_t *mul2, mat_t *result)
{
    int i, j, k;

    for (i = 0; i < mul1->size; i++)
    {
        for (j = 0; j < mul2->size; j++)
        {
            result->matrix[i][j] = 0;

            for (k = 0; k < mul2->size; k++)
            {
                result->matrix[i][j] += mul1->matrix[i][k] * mul2->matrix[k][j];
            }
        }
    }

    print_mat(result);
    return S_SUCCESS;
}

int handleMul(mat_t *all[], char *c)
{
    int status;
    mul_mat_t *my_mat = calloc(1, sizeof(mul_mat_t));

    status = toStructForMul(all, c, my_mat);

    printf("\ntoStructForMul status: %d\n", status);

    status = mul_mat(my_mat->mul1, my_mat->mul2, my_mat->result);

    return status;
}