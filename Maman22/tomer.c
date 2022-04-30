#include "mat.h"

enum STATUS
{
    SUCCESS,
    FAIL_NO_COMMAND,
    FAIL_WRONG_PARAMS,
};

enum COMMAND
{
    PRINT_MAT,
    UNDEFINED
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

    m->size = MAT_SIZE; /* define mat m size */

    /* initiate all matrix cells to 0 */
    for (i = 0; i < m->size * m->size; i++)
    {
        m->matrix[i] = 0; /* define mat m matrix */
    }
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

    MAT_A->size = MAT_SIZE; /* define mat m size */
    MAT_B->size = MAT_SIZE; /* define mat m size */
    MAT_C->size = MAT_SIZE; /* define mat m size */
    MAT_D->size = MAT_SIZE; /* define mat m size */
    MAT_E->size = MAT_SIZE; /* define mat m size */
    MAT_F->size = MAT_SIZE; /* define mat m size */

    /* initiate all matrix cells to 0 */
    for (i = 0; i < MAT_A->size * MAT_A->size; i++)
    {
        MAT_A->matrix[i] = 1; /* define mat m matrix */
        MAT_B->matrix[i] = 2;
        MAT_C->matrix[i] = 3;
        MAT_D->matrix[i] = 4;
        MAT_E->matrix[i] = 5;
        MAT_F->matrix[i] = 6;
    }

    mat_t *all[6];
    all[E_MAT_A] = MAT_A;
    all[E_MAT_B] = MAT_B;
    all[E_MAT_C] = MAT_C;
    all[E_MAT_D] = MAT_D;
    all[E_MAT_E] = MAT_E;
    all[E_MAT_F] = MAT_F;

    print_mat_t *noa = calloc(1, sizeof(print_mat_t));
    int status = toStructForPrint(all, "MAT_F", noa);
   
    if (status != SUCCESS)
        return finish(status);
        
    doPrint(noa->mat);

    return finish(SUCCESS);
}

/* int whichCommand(char *c)
{
    // TODO: make this return print mat
    return UNDEFINED;
}*/

int toStructForPrint(mat_t *all[], char *c, print_mat_t *ptrStruct)
{
    int idx = -1;
    if (strcmp(c, "MAT_A") == 0)
        idx = E_MAT_A;
    else if (strcmp(c, "MAT_B") == 0)
        idx = E_MAT_B;
    else if (strcmp(c, "MAT_C") == 0)
        idx = E_MAT_C;
    else if (strcmp(c, "MAT_D") == 0)
        idx = E_MAT_D;
    else if (strcmp(c, "MAT_E") == 0)
        idx = E_MAT_E;
    else if (strcmp(c, "MAT_F") == 0)
        idx = E_MAT_F;
    else
        return FAIL_WRONG_PARAMS;

    ptrStruct->mat = all[idx];
    return SUCCESS;
}

void doPrint(mat_t *m)
{
    printf("DEBUG: size %d", m->size);
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
        printf("Well done! goodbye.");
        break;
    case FAIL_WRONG_PARAMS:
        printf("the parameters are wrong. please try again");
        break;
    }

    return status;
}