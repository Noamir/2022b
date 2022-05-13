#include "handlers.h"

struct read_mat_def
{
    mat_t *mat;
    double numbers[MAT_SIZE * MAT_SIZE];
};

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

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */
    tmp = (char *)malloc(strlen(c) * sizeof(char));
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

        number = strtod(num_str, &end);

        if (counter < cells_num)
            ptrStruct->numbers[counter] = number;

        /* If ONLY A COMMA LEFT in the whole command */
        if (strcmp(c, ",") == 0)
            return S_FAIL_EXTRA_TEXT;

        if (strcmp(c, "\0") != 0)
        {
            status = validateCommas(c);
            if (status != S_SUCCESS)
                return status;
        }

        strcpy(tmp, c);
        num_str = strtok(tmp, ",");
        counter++;
    }

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

void read_mat(mat_t *mat, double numbers[])
{
    int i, j, k;
    k = 0;

    for (i = 0; i < mat->size; i++)
    {
        for (j = 0; j < mat->size; j++, k++)
            mat->matrix[i][j] = numbers[k];
    }

    print_mat(mat);
}

int handleRead(mat_t *all[], char *c)
{
    int status;
    read_mat_t *my_mat = calloc(1, sizeof(read_mat_t));
    status = toStructForRead(all, c, my_mat);

    if (status != S_SUCCESS)
        return status;

    read_mat(my_mat->mat, my_mat->numbers);

    return status;
}