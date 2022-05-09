#include "mat.h"

int print_mat(mat_t *m);
int whichMat(char *c);
double whichNumber(char *num_str);
int validateMat(int matIdx);
int validateCommas(char *command);
int validateNull(char *command);
void trimLeadingSpaces(char *c);

void trimSpaces(char *c)
{
    int i, j = 0;
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));

    for (i = 0; i < strlen(c); i++)
    {
        if (c[i] != ' ' && c[i] != '\t')
        {
            tmp[j] = c[i];
            j++;
        }
    }
    /* TODO: make sure memory allocation is right */
    strcpy(c, tmp);
}

int toStructForRead(mat_t *all[], char *c, read_mat_t *ptrStruct)
{
    int i, idx, status, counter = 0;
    char *num_str, *tmp, *end;
    double number;

    idx = whichMat(c);

    printf("mat: %d\n", idx);
    printf("currenct command: %s\n", c);

    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */
    tmp = (char *)malloc(strlen(c) * sizeof(char));
    strcpy(tmp, c);

    num_str = strtok(tmp, ",");
    printf("num_str: %s\n", num_str);

    while (num_str != NULL)
    {   
        
        printf("number before trim spaces: '%s'\n", num_str);
        num_str = strtok(num_str, " ");
        printf("number after trim spaces and strtok: '%s'\n", num_str);
        memmove(c, c + strlen(num_str), strlen(c));
        trimLeadingSpaces(num_str);
        number = strtod(num_str, &end);
        printf("number: %f\n", number);
        printf("end: %s\n", end);

        if (strcmp(end, "\0") != 0)
        {
            return S_FAIL_NOT_A_REAL_NUMBER;
        }

        if (counter < 16)
            ptrStruct->numbers[counter] = number;

        /* If its ONLY A COMMA in the whole command */
        if (strcmp(c, ",") == 0)
            return S_FAIL_EXTRA_TEXT; /* no more numbers after comma */

        if (strcmp(c, "\0") != 0)
        {
            status = validateCommas(c);
            printf("VALIDATE COMMA AFTER EACH NUM\n");
            if (status != S_SUCCESS)
                return status;
        }

        strcpy(tmp, c);
        num_str = strtok(tmp, ",");
        printf("num_str: %s\n", num_str);

        counter++;
    }
    if (counter < 16)
    {
        for (i = counter; i < 16; i++)
        {
            ptrStruct->numbers[counter] = DEFAULT_MAT_VAL;
        }
    }

    status = validateNull(c);
    if (status != S_SUCCESS)
        return status;

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