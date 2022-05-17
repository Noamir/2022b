#include "mat.h"
void trimLeadingSpaces(char *c);

/* validateMat: Validate mat index */
int validateMat(int matIdx)
{
    if (matIdx == MAT_NULL)
        return S_FAIL_MISSING_ARGS;
    if (matIdx == MAT_UNDEFINED)
        return S_FAIL_NO_MAT;
    return S_SUCCESS;
}

/* validateReadCommas: Validate the allowed commas in read_mat command */
int validateReadCommas(char *command)
{
    trimLeadingSpaces(command);
    if (strcmp(command, "\0") == 0)
        return S_SUCCESS;
    else if (strncmp(command, ",", strlen(",")) != 0)
        return S_FAIL_MISSING_COMMA;

    memmove(command, command + strlen(","), strlen(command)); /* remove the comma */
    trimLeadingSpaces(command);

    if (strcmp(command, "\0") == 0)
        return S_FAIL_EXTRA_TEXT;
    if (strncmp(command, ",", strlen(",")) == 0)
        return S_FAIL_MULTIPLE_COMMAS;
    return S_SUCCESS;
}

/* validateCommas: Validate commas are in the expected spots for all commands */
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

/* validateScalar: Validate a given string is a valid scalar */
int validateScalar(char *scalar_str)
{
    char *end;
    strtod(scalar_str, &end);
    if (strcmp(end, "\0") != 0)
        return S_FAIL_NOT_A_SCALAR;
    return S_SUCCESS;
}

/* validateNumber: Validate a given string is a valid number */
int validateNumber(char *num_str)
{
    char *end;
    strtod(num_str, &end);
    if (strcmp(end, "\0") != 0)
        return S_FAIL_NOT_A_REAL_NUMBER;
    return S_SUCCESS;
}

/* validateNull: Validate a given string is null */
int validateNull(char *command)
{
    trimLeadingSpaces(command);
    if ((strcmp(command, "\0") != 0) && (command[0] != EOF))
        return S_FAIL_EXTRA_TEXT;
    return S_SUCCESS;
}