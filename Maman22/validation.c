#include "mat.h"

/* // mul_mat MAT_A ,   MAT_B, MAT_C
// MAT_A ,   MAT_B, MAT_C
// MAT_A,MAT_B,MAT_C
// command = MAT_A, origin = MAT_B,MATC
/* expected input: MAT_[A-F](,.*)? */ 
/* int expect_mat(char *command)
{
    if (strlen(command) < 5 || strncmp(command, "MAT_", strlen("MAT_")) != 0) {
        return S_FAIL_WRONG_PARAMS;
    }

    int i = 0;
    char *tmp = (char *)malloc(strlen(command) * sizeof(char));
    char *mat_name;

    strcpy(tmp, command);
    
    while (isalpha(*(command + i)) || (*(command + i)) == '_')
    {   

        i++;
    }

    if (i == 0)
        return S_FAIL_WRONG_PARAMS;

    else
    {
        memmove(command, command + (i * sizeof(char)), strlen(command));
        return S_SUCCESS;
    }
} */

/* int validate(char *command, int argTypes[])
{
    int i = 0, status, argsLen;
    char *tmp = (char *)malloc(strlen(command) * sizeof(char));
    strcpy(tmp, command);
    argsLen = (sizeof(argTypes) / sizeof(argTypes[0]));

    for (i = 0; i < argsLen; i++)
    {
        if (argTypes[i] == A_MAT)
        {
            expect_mat(command);
        } */
      /*   // if this is not the last argument, ensure that there's a comma */
   /*  }

    printf("args length: %d", argsLen);

    printf("validate mat\n");

    return S_SUCCESS;
}
 */