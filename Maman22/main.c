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

        /* initiate all matrix cells to 0 */
        for (j = 0; j < m->size; j++)
        {
            for (k = 0; k < m->size; k++)
            {
                m->matrix[j][k] = DEFAULT_MAT_VAL;
            }
        }
    }
}

char *getCommand()
{
    int limit = DEFAULT_BUFFER, i = 0;
    char *tmp_ptr;
    char *command = (char *)malloc(limit * sizeof(char));

    printf("\nHi, insert command\n");

    /* get command chars from stdin to command pointer */
    for (i = 0; (i <= limit) && (*(command + i) = getchar()) != '\n'; i++)
    {
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

    return command;
}

int whichCommand(char *c)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));
    char *cmd;

    strcpy(tmp, c);

    /* FIXME: How to enable many spaces, tabs.. */
    cmd = strtok(tmp, " \t");

    printf("cmd: %s\n", cmd);

    /* FIXME: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(cmd) + 1, strlen(c));

    if (strcmp(cmd, "print_mat") == 0)
        return CMD_PRINT_MAT;

    else if (strcmp(cmd, "add_mat") == 0)
        return CMD_ADD_MAT;

    else if (strcmp(cmd, "sub_mat") == 0)
        return CMD_SUB_MAT;

    else if (strcmp(cmd, "mul_mat") == 0)
        return CMD_MUL_MAT;

    else if (strcmp(cmd, "read_mat") == 0)
        return CMD_READ_MAT;

    else if (strcmp(cmd, "mul_scalar") == 0)
        return CMD_MUL_SCALAR;

    else if (strcmp(cmd, "trans_mat") == 0)
        return CMD_TRANS_MAT;

    else if (strcmp(cmd, "stop") == 0)
        return CMD_STOP;

    else
        return CMD_UNDEFINED;
}

int whichMat(char *c)
{
    if (strncmp(c, "MAT_A", strlen("MAT_A")) == 0)
        return E_MAT_A;

    else if (strncmp(c, "MAT_B", strlen("MAT_B")) == 0)
        return E_MAT_B;

    else if (strncmp(c, "MAT_C", strlen("MAT_C")) == 0)
        return E_MAT_C;

    else if (strncmp(c, "MAT_D", strlen("MAT_D")) == 0)
        return E_MAT_D;

    else if (strncmp(c, "MAT_E", strlen("MAT_E")) == 0)
        return E_MAT_E;

    else if (strncmp(c, "MAT_F", strlen("MAT_F")) == 0)
        return E_MAT_F;

    else
        return MAT_UNDEFINED;
}

double whichNumber(char *num_str)
{
    char *end;
    double number;

    number = strtod(num_str, &end);

    return number;
}

int finish(int status)
{
    switch (status)
    {
    case S_SUCCESS:
        printf("Well done! goodbye.\n");
        break;
    case S_FAIL_WRONG_PARAMS:
        printf("the parameters are wrong. please try again\n");
        break;
    case S_FAIL_NO_COMMAND:
        printf("the command is wrong. please try again\n");
        break;
    case S_FAIL_MEMORY_ALLOCATION:
        printf("Fatal error: memory allocation failed!\n");
    }

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

        switch (cmd)
        {
        case CMD_PRINT_MAT:
            printf("calling handlePrint()...\n");
            status = handlePrint(all, command_str);
            break;
        case CMD_ADD_MAT:
            printf("calling handleAdd()...\n");
            status = handleAdd(all, command_str);
            break;
        case CMD_SUB_MAT:
            printf("calling handleSub()...\n");
            status = handleSub(all, command_str);
            break;
        case CMD_MUL_MAT:
            printf("calling handleMul()...\n");
            status = handleMul(all, command_str);
            break;
        case CMD_READ_MAT:
            printf("calling handleRead()...\n");
            status = handleRead(all, command_str);
            break;
        case CMD_MUL_SCALAR:
            printf("calling handleMulScalar()...\n");
            status = handleMulScalar(all, command_str);
            break;
        case CMD_TRANS_MAT:
            printf("calling handleTrans()...\n");
            status = handleTrans(all, command_str);
            break;
        case CMD_STOP:
            printf("Stopping...\n");
            exit(0);
        case CMD_UNDEFINED:
            printf("Command undifiend, please try again.\n");
            status = S_FAIL_NO_COMMAND;
            break;
        }
    }

    return finish(status);
}
