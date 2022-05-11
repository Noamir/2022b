#include "mat.h"

int handlePrint(mat_t *all[], char *c);
int handleAdd(mat_t *all[], char *c);
int handleSub(mat_t *all[], char *c);
int handleMul(mat_t *all[], char *c);
int handleRead(mat_t *all[], char *c);
int handleMulScalar(mat_t *all[], char *c);
int handleTrans(mat_t *all[], char *c);

void initMats(mat_t *mats[])
{
    int i, j, k;
    mat_t *m;

    for (i = 0; i < 6; i++)
    {
        m = mats[i];

        m->size = MAT_SIZE;

        /* initiate all matrix cells to DEFAULT_MAT_VAL */
        for (j = 0; j < m->size; j++)
        {
            for (k = 0; k < m->size; k++)
            {
                m->matrix[j][k] = DEFAULT_MAT_VAL;
            }
        }
    }
}

void finish(int status)
{
    switch (status)
    {
    case S_SUCCESS:
        printf("\nSuccess\n");
        break;
    case S_FAIL_NO_COMMAND:
        printf("\nUndefined command name\n");
        break;
    case S_FAIL_NO_MAT:
        printf("\nUndefined matrix name\n");
        break;
    case S_FAIL_NOT_A_REAL_NUMBER:
        printf("\nArgument is not a real number\n");
        break;
    case S_FAIL_NOT_A_SCALAR:
        printf("\nArgument is not a scalar\n");
        break;
    case S_FAIL_EXTRA_TEXT:
        printf("\nExtraneous text after end of command\n");
        break;
    case S_FAIL_MISSING_ARGS:
        printf("\nMissing argument\n");
        break;
    case S_FAIL_ILLEGAL_COMMA:
        printf("\nIllegal comma\n");
        break;
    case S_FAIL_MISSING_COMMA:
        printf("\nMissing comma\n");
        break;
    case S_FAIL_MULTIPLE_COMMAS:
        printf("\nMultiple consecutive commas\n");
        break;
    case S_FAIL_NOT_SCALAR:
        printf("\nArgument is not a scalar\n");
        break;
    case S_FAIL_ETRA_TEXT_END:
        printf("\nExtraneous text after end of command\n");
        break;
    case S_FAIL_NO_SPACE:
        printf("\nMust be at least 1 space after command\n");
        break;
    case S_FAIL_MEMORY_ALLOCATION:
        printf("\nFatal error: memory allocation failed!\n");
        break;
    case S_FAIL_EOF:
        printf("\nInput got EOF char. Illigal. Stopping the program with error.\n");
        break;
    }
}

char *getCommand()
{
    int limit = DEFAULT_BUFFER, i = 0;
    char *tmp_ptr;
    char *command = (char *)malloc(limit * sizeof(char));

    printf("\nHi, insert a new command\n");

    /* get command chars from stdin to command pointer */
    /* TODO: get input from file is not ending aith \n - handle */
    for (i = 0; (i <= limit) && (*(command + i) = getchar()) != '\n'; i++)
    {
        if (*(command + i) == EOF)
        {
            finish(S_FAIL_EOF);
            exit(S_FAIL_EOF);
        }
        /* got to the limit of chars size - increase limit and realloc command with new limit size */
        if (i == limit - 1)
        {
            limit = 2 * limit;
            tmp_ptr = (char *)realloc(command, limit * sizeof(char));

            /* if dynamic allocation failed - return NULL */
            if (tmp_ptr == NULL)
            {
                return NULL;
            }

            command = tmp_ptr;
        }
    }

    /* replace \n with \0 - NULL */
    command[i] = '\0';

    printf("\nThe command is: %s\n", command);

    return command;
}

void trimLeadingSpaces(char *c)
{
    int i = 0;
    while (c[i] == ' ' || c[i] == '\t')
        i++;

    if (i > 0)
        memmove(c, c + i * sizeof(char), strlen(c));
}

int whichCommand(char *c)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *cmd;
    int status;

    if (strcmp(c, "\0") == 0)
        return CMD_UNDEFINED;

    trimLeadingSpaces(c);

    strcpy(tmp, c);

    cmd = strtok(tmp, " \t"); /* looks for the first space or tab. If there are no such - return all string */

    /* FIXME: How to forward pointer correctly - how to free spaces I skipped here */

    if (strncmp(cmd, "print_mat", strlen("print_mat")) == 0)
    {
        memmove(c, c + strlen("print_mat"), strlen(c));
        status = CMD_PRINT_MAT;
    }
    else if (strncmp(cmd, "add_mat", strlen("add_mat")) == 0)
    {
        memmove(c, c + strlen("add_mat"), strlen(c));
        status = CMD_ADD_MAT;
    }
    else if (strncmp(cmd, "sub_mat", strlen("sub_mat")) == 0)
    {
        memmove(c, c + strlen("sub_mat"), strlen(c));
        status = CMD_SUB_MAT;
    }
    else if (strncmp(cmd, "mul_mat", strlen("mul_mat")) == 0)
    {
        memmove(c, c + strlen("mul_mat"), strlen(c));
        status = CMD_MUL_MAT;
    }
    else if (strncmp(cmd, "read_mat", strlen("read_mat")) == 0)
    {
        memmove(c, c + strlen("read_mat"), strlen(c));
        status = CMD_READ_MAT;
    }
    else if (strncmp(cmd, "mul_scalar", strlen("mul_scalar")) == 0)
    {
        memmove(c, c + strlen("mul_scalar"), strlen(c));
        status = CMD_MUL_SCALAR;
    }
    else if (strncmp(cmd, "trans_mat", strlen("trans_mat")) == 0)
    {
        memmove(c, c + strlen("trans_mat"), strlen(c));
        status = CMD_TRANS_MAT;
    }
    else if (strncmp(cmd, "stop", strlen("stop")) == 0)
    {
        memmove(c, c + strlen("stop"), strlen(c));
        status = CMD_STOP;
    }
    else
        return CMD_UNDEFINED;
    
    if((strncmp(c, " ", strlen(" ")) != 0) && (status != CMD_STOP))
        return CMD_NO_SPACE;

    free(tmp);
    return status;
}

int whichMat(char *c)
{
    int status;
    trimLeadingSpaces(c);

    if (strcmp(c, "\0") == 0)
        return MAT_NULL;

    if (strncmp(c, "MAT_A", strlen("MAT_A")) == 0)
    {
        memmove(c, c + strlen("MAT_A"), strlen(c));
        status = E_MAT_A;
    }
    else if (strncmp(c, "MAT_B", strlen("MAT_B")) == 0)
    {
        memmove(c, c + strlen("MAT_B"), strlen(c));
        status = E_MAT_B;
    }
    else if (strncmp(c, "MAT_C", strlen("MAT_C")) == 0)
    {
        memmove(c, c + strlen("MAT_C"), strlen(c));
        status = E_MAT_C;
    }
    else if (strncmp(c, "MAT_D", strlen("MAT_D")) == 0)
    {
        memmove(c, c + strlen("MAT_D"), strlen(c));
        status = E_MAT_D;
    }
    else if (strncmp(c, "MAT_E", strlen("MAT_E")) == 0)
    {
        memmove(c, c + strlen("MAT_E"), strlen(c));
        status = E_MAT_E;
    }
    else if (strncmp(c, "MAT_F", strlen("MAT_F")) == 0)
    {
        memmove(c, c + strlen("MAT_F"), strlen(c));
        status = E_MAT_F;
    }
    else
    {
        return MAT_UNDEFINED;
    }

    if ((strcmp(c, "\0") != 0) && (strncmp(c, " ", strlen(" ")) != 0) && (strncmp(c, "\t", strlen("\t")) != 0) && (strncmp(c, ",", strlen("\t")) != 0))
        return MAT_UNDEFINED;

    return status;
}

int main()
{
    mat_t *MAT_A = calloc(1, sizeof(mat_t));
    mat_t *MAT_B = calloc(1, sizeof(mat_t));
    mat_t *MAT_C = calloc(1, sizeof(mat_t));
    mat_t *MAT_D = calloc(1, sizeof(mat_t));
    mat_t *MAT_E = calloc(1, sizeof(mat_t));
    mat_t *MAT_F = calloc(1, sizeof(mat_t));

    int status;
    char *command_str;
    int cmd;

    mat_t *all[6];
    all[E_MAT_A] = MAT_A;
    all[E_MAT_B] = MAT_B;
    all[E_MAT_C] = MAT_C;
    all[E_MAT_D] = MAT_D;
    all[E_MAT_E] = MAT_E;
    all[E_MAT_F] = MAT_F;

    initMats(all);

    while (1)
    {
        command_str = getCommand();

        if (command_str == NULL)
        {
            finish(S_FAIL_MEMORY_ALLOCATION);
        }

        cmd = whichCommand(command_str);
        trimLeadingSpaces(command_str);

        if (strncmp(command_str, ",", 1) == 0)
        {
            finish(S_FAIL_ILLEGAL_COMMA);
            continue;
        }

        switch (cmd)
        {
        case CMD_PRINT_MAT:
            status = handlePrint(all, command_str);
            break;
        case CMD_ADD_MAT:
            status = handleAdd(all, command_str);
            break;
        case CMD_SUB_MAT:
            status = handleSub(all, command_str);
            break;
        case CMD_MUL_MAT:
            status = handleMul(all, command_str);
            break;
        case CMD_READ_MAT:
            status = handleRead(all, command_str);
            break;
        case CMD_MUL_SCALAR:
            status = handleMulScalar(all, command_str);
            break;
        case CMD_TRANS_MAT:
            status = handleTrans(all, command_str);
            break;
        case CMD_STOP:
            if (strcmp(command_str, "\0") == 0)
            {
                printf("Stopping...\n");
                exit(S_SUCCESS);
            }
            status = S_FAIL_ETRA_TEXT_END;
            break;
        case CMD_NO_SPACE:
            status = S_FAIL_NO_SPACE;
            break;
        case CMD_UNDEFINED:
            status = S_FAIL_NO_COMMAND;
            break;
        }

        finish(status);
        free(command_str);
    }

    return 0;
}
