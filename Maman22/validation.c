#include "mat.h"
void trimLeadingSpaces(char *c);
void finish(int status);

int validateMat(int matIdx)
{
    if (matIdx == MAT_NULL)
        return S_FAIL_MISSING_ARGS;

    if (matIdx == MAT_UNDEFINED)
        return S_FAIL_NO_MAT;

    return S_SUCCESS;
}

int validateCommas(char *command)
{
    trimLeadingSpaces(command);
    if (strcmp(command, "\0") == 0)
        return S_FAIL_MISSING_ARGS;
    else if (strncmp(command, ",", strlen(",")) != 0)
        return S_FAIL_MISSING_COMMA;

    memmove(command, command + strlen(","), strlen(command)); /* remove the comma */
    trimLeadingSpaces(command);

    if (strcmp(command, "\0") == 0)
        return S_FAIL_MISSING_ARGS;
    if (strncmp(command, ",", strlen(",")) == 0)
        return S_FAIL_MULTIPLE_COMMAS;

    return S_SUCCESS;
}

int validateScalar(char *scalar_str)
{
    char *end;
    strtod(scalar_str, &end);
    if (strcmp(end, "\0") != 0)
        return S_FAIL_NOT_A_SCALAR;

    return S_SUCCESS;
}

int validateNumber(char *num_str)
{
    char *end;
    strtod(num_str, &end);
    if (strcmp(end, "\0") != 0)
        return S_FAIL_NOT_A_REAL_NUMBER;

    return S_SUCCESS;
}

int validateNull(char *command)
{
    trimLeadingSpaces(command);

    if (strcmp(command, "\0") != 0)
        return S_FAIL_EXTRA_TEXT;

    return S_SUCCESS;
}