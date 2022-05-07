#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
double whichNumber(char *num_str);

int toStructForRead(mat_t *all[], char *c, read_mat_t *ptrStruct)
{
    int i, idx;
    char *num_str, *tmp, *end;
    double number;

    idx = whichMat(c);

    printf("mat: %d\n", idx);
    printf("currenct command: %s\n", c);

    /* Validations */

    if (idx == MAT_NULL)
    {
        return S_FAIL_MISSING_ARGS;
    }

    if (idx == MAT_UNDEFINED)
    {
        return S_FAIL_NO_MAT;
    }

    if (strncmp(c, ",", strlen(",")) != 0)
        return S_FAIL_MISSING_COMMA;

    memmove(c, c + 1 * sizeof(char), strlen(c)); /* remove the comma */
    printf("currenct command: %s\n", c);

    if (strncmp(c, ",", strlen(",")) == 0)
        return S_FAIL_MULTIPLE_COMMAS;

    /* End of validation */

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */
    tmp = (char *)malloc(strlen(c) * sizeof(char));
    strcpy(tmp, c);

    num_str = strtok(tmp, ",");
    printf("num_str: %s\n", num_str);

    for (i = 0; i < MAT_SIZE * MAT_SIZE; i++)
    {
        if (num_str)
        {
            number = strtod(num_str, &end);
            printf("number: %f\n", number);
            printf("end: %s\n", end);

            if (strcmp(end, "\0") != 0)
            {
                return S_FAIL_NOT_A_REAL_NUMBER;
            }

            ptrStruct->numbers[i] = number;
            memmove(c, c + strlen(num_str) + 1, strlen(c));
            strcpy(tmp, c);
            num_str = strtok(tmp, ",");
            printf("num_str: %s\n", num_str);
        }
        else
        {
            ptrStruct->numbers[i] = DEFAULT_MAT_VAL;
        }
    }
    if (strcmp(c, "\0") != 0)
    {
        return S_FAIL_EXTRA_TEXT;
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

    if (status != S_SUCCESS)
        return status;

    status = read_mat(my_mat->mat, my_mat->numbers);

    return status;
}