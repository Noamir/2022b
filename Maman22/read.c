#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);

double *whichNumber(char *c)
{
    printf("hello\n");
    char *end;
    double *numbers = (double *)malloc(20 * sizeof(double));
    ;

    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *num_str;
    strcpy(tmp, c);
    num_str = strtok(tmp, ",");
    printf("num_str is: %s\n", num_str);

    int i = 0;

    while (num_str != NULL)
    {
        *(numbers + i) = strtod(num_str, &end);
        printf("number is: %.2f\n", *(numbers + i));

        memmove(c, c + strlen(num_str) + 1, strlen(c));

        strcpy(tmp, c);
        num_str = strtok(tmp, ",");
        printf("num_str is: %s\n", num_str);

        printf("current c is: %s\n", c);

        i++;
    }

    return numbers;
}

int toStructForRead(mat_t *all[], char *c, read_mat_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *mat_str, *num_str;
    int idx;
    double *numbers = (double *)malloc(20 * sizeof(double));

    strcpy(tmp, c);

    mat_str = strtok(tmp, ",");

    printf("mat_str: %s\n", mat_str);

    idx = whichMat(mat_str);

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(mat_str) + 1, strlen(c));

    strcpy(tmp, c);

    numbers = whichNumber(c);

    ptrStruct->numbers = numbers;

    free(tmp);

    return S_SUCCESS;
}

int read_mat(mat_t *mat, double *nums)
{
    int i, j, k;
    k = 0;

    for (i = 0; i < mat->size; i++)
    {
        for (j = 0; j < mat->size; j++)
        {
            mat->matrix[i][j] = *(nums + k);
            k++;
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