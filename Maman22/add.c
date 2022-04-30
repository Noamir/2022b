#include "mat.h"

int print_mat(mat_t *m);

int toStructForAdd(mat_t *all[], char *c, add_mat_t *ptrStruct)
{
    int i;
    printf("DEBUG 1: current command is: %s \n", c);

    for (i = 0; i < 3; i++)
    {
        char *tmp = (char *)malloc(strlen(c) * sizeof(char));
        char *mat_name;
        int idx;
        
        strcpy(tmp, c);

        mat_name = strtok(tmp, ",");

        printf("DEBUG 2: current mat_name is: %s \n", mat_name);

        /* FIXME: How to forward pointer correctly - how to free spaces I skipped here */

        memmove(c, c + strlen(mat_name) + 1, strlen(c));


        printf("DEBUG 3: current command is: %s \n", c);


        if (strncmp(mat_name, "MAT_A", strlen("MAT_A")) == 0)
        {
            idx = E_MAT_A;
        }
        else if (strncmp(mat_name, "MAT_B", strlen("MAT_B")) == 0)
        {
            idx = E_MAT_B;
        }
        else if (strncmp(mat_name, "MAT_C", strlen("MAT_C")) == 0)
        {
            idx = E_MAT_C;
        }
        else if (strncmp(mat_name, "MAT_D", strlen("MAT_D")) == 0)
        {
            idx = E_MAT_D;
        }
        else if (strncmp(mat_name, "MAT_E", strlen("MAT_E")) == 0)
        {
            idx = E_MAT_E;
        }
        else if (strncmp(mat_name, "MAT_F", strlen("MAT_F")) == 0)
        {
            idx = E_MAT_F;
        }
        else
        {
            return S_FAIL_WRONG_PARAMS;
        }

        ptrStruct->mats[i] = all[idx];
    }

    return S_SUCCESS;
}

int add_mat(mat_t *m1, mat_t *m2, mat_t *m3)
{
    int i;

    for (i = 0; i < m3->size * m3->size; i++)
    {
        m3->matrix[i] = m1->matrix[i] + m2->matrix[i];
    }

    print_mat(m3);

    return S_SUCCESS;
}

int handleAdd(mat_t *all[], char *c)
{
    int status;
    add_mat_t *my_mat = calloc(1, sizeof(add_mat_t));

    status = toStructForAdd(all, c, my_mat);

    printf("\ntoStructForAdd status: %d\n", status);

    status = add_mat(my_mat->mats[0], my_mat->mats[1], my_mat->mats[2]);

    return S_SUCCESS;
}