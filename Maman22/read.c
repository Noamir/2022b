#include "handlers.h"
int validateReadCommas(char *command);

struct read_mat_def
{
    mat_t *mat;
    double numbers[MAT_SIZE * MAT_SIZE];
};

/* toStructForRead: Get read_mat command string, validate its components, adapt it to read_mat struct */
int toStructForRead(mat_t *all[], char *c, read_mat_t *ptrStruct)
{
    int i, idx, status, counter = 0, cells_num;
    char *num_str, *tmp, *end;
    double number;

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mat = all[idx];
    cells_num = ptrStruct->mat->size * ptrStruct->mat->size;

    tmp = (char *)malloc(strlen(c) * sizeof(char));
    if (tmp == NULL)
        statusHandler(S_FAIL_MEMORY_ALLOCATION);

    strcpy(tmp, c);
    num_str = strtok(tmp, ",");

    while (num_str != NULL)
    {
        num_str = strtok(num_str, " ");
        memmove(c, c + strlen(num_str), strlen(c));
        trimLeadingSpaces(num_str);

        status = validateNumber(num_str);
        if (status != S_SUCCESS)
            return status;

        /* if num_str represents a real number - transfer it from string to double */
        number = strtod(num_str, &end);

        if (counter < cells_num)
            ptrStruct->numbers[counter] = number;
            
        if (strcmp(c, "\0") != 0)
        {
            status = validateReadCommas(c);
            if (status != S_SUCCESS)
                return status;
        }

        strcpy(tmp, c);
        num_str = strtok(tmp, ",");
        counter++;
    }

    /* if got less numbers than matrix cells, fill the rest of cells in matrix with DEFAULT_MAT_VAL */
    if (counter < cells_num)
    {
        for (i = counter; i < cells_num; i++)
            ptrStruct->numbers[counter] = DEFAULT_MAT_VAL;
    }

    status = validateNull(c);
    if (status != S_SUCCESS)
        return status;

    free(tmp);
    return S_SUCCESS;
}

/* readMat: Get a mat and array of numbers. Insert numbers to mat cells.*/
void readMat(mat_t *mat, double numbers[])
{
    int i, j, k;
    k = 0;

    for (i = 0; i < mat->size; i++)
    {
        for (j = 0; j < mat->size; j++, k++)
            mat->matrix[i][j] = numbers[k];
    }

    printMat(mat);
}

/* handleRead: Handle read_mat process - from string input to execution */
int handleRead(mat_t *all[], char *c)
{
    int status;
    read_mat_t *my_mat = calloc(1, sizeof(read_mat_t));
    if (my_mat == NULL)
        statusHandler(S_FAIL_MEMORY_ALLOCATION);

    status = toStructForRead(all, c, my_mat);
    if (status != S_SUCCESS)
        return status;

    readMat(my_mat->mat, my_mat->numbers);
    free(my_mat);
    return status;
}