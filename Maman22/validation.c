#include "mat.h"

int validateMat(int matIdx)
{
    int status;

    if (matIdx == MAT_NULL)
    {
        return S_FAIL_MISSING_ARGS;
    }

    if (matIdx == MAT_UNDEFINED)
    {
        return S_FAIL_NO_MAT;
    }

    return S_SUCCESS;
}


int validateNull(char *command)
{
    if (strcmp(command, "\0") != 0)
    {
        return S_FAIL_EXTRA_TEXT;
    }

    return S_SUCCESS;
}