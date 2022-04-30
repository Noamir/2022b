#include "mat.h"

int handlePrint(mat_t *all[], char *c);
int handleAdd(mat_t *all[], char *c);

void init_mat(mat_t *m)
{
    int i;
    m = calloc(1, sizeof(mat_t));

    m->size = MAT_SIZE;

    /* initiate all matrix cells to 0 */
    for (i = 0; i < m->size * m->size; i++)
    {
        m->matrix[i] = 0;
    }
}

char *get_command()
{
    int limit = 10, i = 0;
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

    cmd = strtok(tmp, " ");

    /* FIXME: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(cmd) + 1, strlen(c));

    if (strcmp(cmd, "print_mat") == 0)
        return CMD_PRINT_MAT;
    else if (strcmp(cmd, "add_mat") == 0)
        return CMD_ADD_MAT;
    else
        return CMD_UNDEFINED;
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
    }

    return status;
}

int main()
{
    mat_t *MAT_A;
    mat_t *MAT_B;
    mat_t *MAT_C;
    mat_t *MAT_D;
    mat_t *MAT_E;
    mat_t *MAT_F;

    int i;
    int status;
    char *command_str;
    int cmd;

    mat_t *all[6];

    MAT_A = calloc(1, sizeof(mat_t));
    MAT_B = calloc(1, sizeof(mat_t));
    MAT_C = calloc(1, sizeof(mat_t));
    MAT_D = calloc(1, sizeof(mat_t));
    MAT_E = calloc(1, sizeof(mat_t));
    MAT_F = calloc(1, sizeof(mat_t));

    MAT_A->size = MAT_SIZE;
    MAT_B->size = MAT_SIZE;
    MAT_C->size = MAT_SIZE;
    MAT_D->size = MAT_SIZE;
    MAT_E->size = MAT_SIZE;
    MAT_F->size = MAT_SIZE;

    for (i = 0; i < 16; i++)
    {
        MAT_A->matrix[i] = 0;
        MAT_B->matrix[i] = 1;
        MAT_C->matrix[i] = 2;
        MAT_D->matrix[i] = 3;
        MAT_E->matrix[i] = 4;
        MAT_F->matrix[i] = 5;
    }

    all[E_MAT_A] = MAT_A;
    all[E_MAT_B] = MAT_B;
    all[E_MAT_C] = MAT_C;
    all[E_MAT_D] = MAT_D;
    all[E_MAT_E] = MAT_E;
    all[E_MAT_F] = MAT_F;

    command_str = get_command();

    if (command_str == NULL)
    {
        printf("Fatal error: memory allocation failed!\n");
        return 1;
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
    case CMD_UNDEFINED:
        status = S_FAIL_NO_COMMAND;
        break;
    }

    return finish(status);
}
