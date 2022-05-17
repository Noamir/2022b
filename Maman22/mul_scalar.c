#include "handlers.h"

struct mul_scalar_def
{
    mat_t *mat;
    double scalar;
    mat_t *result;
};

/* toStructForMulScalar: Get mul_scalar command string, validate its components, adapt it to mul_scalar struct */
int toStructForMulScalar(mat_t *all[], char *c, mul_scalar_t *ptrStruct)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    
    char *scalar_str, *end;
    int idx, status;
    double scalar;

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->mat = all[idx];

    /* TODO: How to forward pointer correctly - how to free spaces I skipped here */
    strcpy(tmp, c);
    scalar_str = strtok(tmp, ",");
    scalar_str = strtok(scalar_str, " ");
    status = validateScalar(scalar_str);
    if (status != S_SUCCESS)
        return status;
    
    scalar = strtod(scalar_str, &end);
    ptrStruct->scalar = scalar;

    memmove(c, c + strlen(scalar_str), strlen(c));

    status = validateCommas(c);
    if (status != S_SUCCESS)
        return status;

    idx = whichMat(c);
    status = validateMat(idx);
    if (status != S_SUCCESS)
        return status;

    status = validateNull(c);
    if (status != S_SUCCESS)
        return status;

    ptrStruct->result = all[idx];

    free(tmp);

    return status;
}

/* subMat: Get a mat, a number, multiple mat cells with the number and insert result to mat result */
void mulScalar(mat_t *mat, double scalar, mat_t *result)
{
    int i, j;
    for (i = 0; i < result->size; i++)
    {
        for (j = 0; j < result->size; j++)
            result->matrix[i][j] = mat->matrix[i][j] * scalar;
    }

    printMat(result);
}

/* handleMulScalar: Handle mul_scalar process - from string input to execution */
int handleMulScalar(mat_t *all[], char *c)
{
    int status;
    mul_scalar_t *my_mat = calloc(1, sizeof(mul_scalar_t));
    status = toStructForMulScalar(all, c, my_mat);
    if (status != S_SUCCESS)
        return status;

    mulScalar(my_mat->mat, my_mat->scalar, my_mat->result);
    return status;
}