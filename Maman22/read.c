#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
double whichNumber(char *num_str);

int toStructForRead(mat_t *all[], char *c, read_mat_t *ptrStruct)
{
    int i, idx;
    char *mat_str, *num_str;
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));

    strcpy(tmp, c);
    mat_str = strtok(tmp, ",");
    idx = whichMat(mat_str);
    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(mat_str) + 1, strlen(c));
    strcpy(tmp, c);
    num_str = strtok(tmp, ",");

    for (i = 0; i < MAT_SIZE * MAT_SIZE; i++)
    {
        if (num_str)
        {
            ptrStruct->numbers[i] = whichNumber(num_str);
            memmove(c, c + strlen(num_str) + 1, strlen(c));
            strcpy(tmp, c);
            num_str = strtok(tmp, ",");
        }
        else
        {
            ptrStruct->numbers[i] = DEFAULT_MAT_VAL;
        }
    }

    free(tmp);

    return S_SUCCESS;
}

int read_mat(mat_t *mat, double numbers[])
{
    int i, j, k;
    k = 0;

    for (i = 0; i < mat->size; i++)
    {
        for (j = 0; j < mat->size; j++, k++)
        {
            mat->matrix[i][j] = numbers[k];
        }
    }

    print_mat(mat);
    return S_SUCCESS;
}

int handleRead(mat_t *all[], char *c)
{
    int status;

    read_mat_t *my_mat = calloc(1, sizeof(read_mat_t));

    status = toStructForRead(all, c, my_mat);

    printf("\ntoStructForRead status: %d\n", status);

    status = read_mat(my_mat->mat, my_mat->numbers);

    return status;
}