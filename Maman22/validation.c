#include "mat.h"

int validateMat(int matIdx)
{
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

int validateCommas(char *command)
{

    if (strcmp(command, "\0") == 0)
    {
        return S_FAIL_MISSING_ARGS;
    }
    else if (strncmp(command, ",", strlen(",")) != 0)
        return S_FAIL_MISSING_COMMA;

    memmove(command, command + strlen(","), strlen(command)); /* remove the comma */
    printf("currenct command: %s\n", command);

    if (strcmp(command, "\0") == 0)
    {
        return S_FAIL_MISSING_ARGS;
    }
    if (strncmp(command, ",", strlen(",")) == 0)
        return S_FAIL_MULTIPLE_COMMAS;

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


