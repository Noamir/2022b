#include "mat.h"



/* expected input: MAT_[A-F] */
int expect_str(char *command)
{
    int i = 0;
    while (isalpha(*(command + i)) || isdigit(*(command + i)) || (*(command + i)) == '_' || (*(command + i)) == '.')
    {
        i++;
    }

    if (i == 0)
        return S_FAIL_NOT_STR;

    else
    {
        memmove(command, command + (i * sizeof(char)), strlen(command));
        return S_SUCCESS;
    }
}

int validatePrint(char *command, int argTypes[], int argsNum)
{
    int i = 0, status;
    char *tmp = (char *)malloc(strlen(command) * sizeof(char));
    strcpy(tmp, command);

    printf("validate mat\n");
    status = trimSpaces(command);

    return S_SUCCESS;
}
