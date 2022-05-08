#include "mat.h"
void trimLeadingSpaces(char *c);

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
    trimLeadingSpaces(command);
    printf("comma first trim: %s\n", command);
    if (strcmp(command, "\0") == 0)
    {
        return S_FAIL_MISSING_ARGS;
    }
    else if (strncmp(command, ",", strlen(",")) != 0)
        return S_FAIL_MISSING_COMMA;

    memmove(command, command + strlen(","), strlen(command)); /* remove the comma */
    printf("comma second trim: %s\n", command);

    trimLeadingSpaces(command);
    printf("comma last trim: %s\n", command);

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
