#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

double whichNumber(char *c)
{
    char *end;
    double number;

    number = strtod(c, &end);

    printf("number is: %7.2f\n", number);
    return number;
}

int toStructForRead(mat_t *all[], char *c, read_mat_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *mat_str, *num_str;
    int idx;
    double number;

    strcpy(tmp, c);

    mat_str = strtok(tmp, ",");

    printf("mat_str: %s\n", mat_str);

    idx = whichMat(mat_str);

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(mat_str) + 1, strlen(c));

    strcpy(tmp, c);

    num_str = strtok(tmp, ",");

    printf("num_str: %s\n", num_str);

    /* convert str to double */
    number = whichNumber(num_str);

    ptrStruct->number = number;

    free(tmp);

    return S_SUCCESS;
}

int read_mat(mat_t *mat, double num)
{
    int i, j;

    for (i = 0; i < mat->size; i++)
    {
        for (j = 0; j < mat->size; j++)
        {
            mat->matrix[i][j] = num;
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

    status = read_mat(my_mat->mat, my_mat->number);

    return status;
}