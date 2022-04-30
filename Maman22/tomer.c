#include "mat.h"

enum STATUS
{
    SUCCESS,
    FAIL_NO_COMMAND,
    FAIL_WRONG_PARAMS,
};

enum COMMAND
{
    CMD_PRINT_MAT,
    CMD_UNDEFINED
};

enum MATRIX
{
    E_MAT_A,
    E_MAT_B,
    E_MAT_C,
    E_MAT_D,
    E_MAT_E,
    E_MAT_F
};

void init_mat(mat_t *m)
{
    m = calloc(1, sizeof(mat_t));
    int i;

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

    printf("\nThe full command as string:\n");
    printf("%s\n", command);

    return command;
}

int main()
{
    mat_t *MAT_A;
    mat_t *MAT_B;
    mat_t *MAT_C;
    mat_t *MAT_D;
    mat_t *MAT_E;
    mat_t *MAT_F;

    MAT_A = calloc(1, sizeof(mat_t));
    MAT_B = calloc(1, sizeof(mat_t));
    MAT_C = calloc(1, sizeof(mat_t));
    MAT_D = calloc(1, sizeof(mat_t));
    MAT_E = calloc(1, sizeof(mat_t));
    MAT_F = calloc(1, sizeof(mat_t));

    int i;
    int status;
    char *command_str;

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

    mat_t *all[6];
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

    status = whichCommand(command_str);

    printf("\nwhichCommand status: %d\n", status);

    print_mat_t *my_mat = calloc(1, sizeof(print_mat_t));

    status = toStructForPrint(all, command_str, my_mat);

    printf("\ntoStructForPrint status: %d\n", status);

    doPrint(my_mat->mat);

    return finish(SUCCESS);
}

int whichCommand(char *c)
{
    char *tmp = (char *)malloc(strlen(c) * sizeof(char));

    strcpy(tmp, c);

    char *cmd;
    cmd = strtok(tmp, " ");

    /* FIXME: How to forward pointer correctly - how to free spaces I skipped here */

    memmove(c, c + strlen(cmd) + 1, strlen(c));

    if (strcmp(cmd, "print_mat") == 0)
        return CMD_PRINT_MAT;
    else
        return CMD_UNDEFINED;
}

int toStructForPrint(mat_t *all[], char *c, print_mat_t *ptrStruct)
{
    int idx;

    if (strncmp(c, "MAT_A", strlen("MAT_A")) == 0)
    {
        idx = E_MAT_A;
    }
    else if (strncmp(c, "MAT_B", strlen("MAT_B")) == 0)
    {
        idx = E_MAT_B;
    }
    else if (strncmp(c, "MAT_C", strlen("MAT_C")) == 0)
    {
        idx = E_MAT_C;
    }
    else if (strncmp(c, "MAT_D", strlen("MAT_D")) == 0)
    {
        idx = E_MAT_D;
    }
    else if (strncmp(c, "MAT_E", strlen("MAT_E")) == 0)
    {
        idx = E_MAT_E;
    }
    else if (strncmp(c, "MAT_F", strlen("MAT_F")) == 0)
    {
        idx = E_MAT_F;
    }
    else
    {
        return FAIL_WRONG_PARAMS;
    }

    ptrStruct->mat = all[idx];
    return SUCCESS;
}

void doPrint(mat_t *m)
{
    int i = 0;
    int j = 0;

    printf("\n\n");
    for (i = 0; i < m->size * m->size; i++, j++)
    {

        if (j == m->size)
        {
            printf("\n");
            j = 0;
        }
        printf("%7.2f  ", m->matrix[i]);
    }
    printf("\n\n");
}

int finish(int status)
{
    switch (status)
    {
    case SUCCESS:
        printf("Well done! goodbye.\n");
        break;
    case FAIL_WRONG_PARAMS:
        printf("the parameters are wrong. please try again\n");
        break;
    }

    return status;
}
