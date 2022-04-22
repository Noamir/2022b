#include "mat.h"

mat *init_mat(mat *m) /* m is pointer to the actual mat address - we make changes on the mat */
{
    int i;

    m->size = MAT_SIZE; /* define mat m size */

    /* initiate all matrix cells to 0 */
    for (i = 0; i < m->size * m->size; i++)
    {
        m->matrix[i] = 0; /* define mat m matrix */
    }

    return m;
}

void print_mat(mat *m) /* m is local - used to print, no changes made */
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

void read_mat(mat *m, float input[]) /* m is pointer to the actual mat address - we make changes on the mat */
{
    int i;

    /* check 2 conditions:
    1. didn't get to the end of m->matrix which is 16 cells
    2. didn't get to the end of input array

    if one of those ended - finish the insertion!  */

    for (i = 0; (i < (m->size * m->size)) && ((input[i]) != 0); i++)
    {
        m->matrix[i] = input[i];
    }
}

char *get_command()
{
    int limit = 10, i = 0;
    char *tmp_ptr;
    char *command = (char *)malloc(limit * sizeof(char));

    /* menu of possible actions: */
    printf("\nWelcome to the best matrix calculator ever! Here are your commands options:\n");

    printf("\n1. read_mat <MATRIX_NAME>,<value>,<value>,<value>");
    printf("\n2. print_mat <MATRIX_NAME>");
    printf("\n3. add_mat <MATRIX_NAME>,<MATRIX_NAME>,<MATRIX_NAME>");
    printf("\n4. sub_mat <MATRIX_NAME>,<MATRIX_NAME>,<MATRIX_NAME>");
    printf("\n5. mul_mat <MATRIX_NAME>,<MATRIX_NAME>,<MATRIX_NAME>");
    printf("\n6. mul_scalar <MATRIX_NAME>,<scaler value>,<MATRIX_NAME>");
    printf("\n7. trans_mat <MATRIX_NAME>,<MATRIX_NAME>");
    printf("\n8. stop - to finish the plan");

    printf("\n\nEnter desired command, click Enter to execute: \n");

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

    printf("\nthe command as string:\n");
    printf("%s ", command);

    return command;
}

int main()
{
    char *command;

    mat *MAT_A = calloc(1, sizeof(mat));
    mat *MAT_B = calloc(1, sizeof(mat));
    mat *MAT_C = calloc(1, sizeof(mat));
    mat *MAT_D = calloc(1, sizeof(mat));
    mat *MAT_E = calloc(1, sizeof(mat));
    mat *MAT_F = calloc(1, sizeof(mat));

    /* init default mats cells with 0 */
    init_mat(MAT_A);
    init_mat(MAT_B);
    init_mat(MAT_C);
    init_mat(MAT_D);
    init_mat(MAT_E);
    init_mat(MAT_F);

    /* get command for matrix action from stdin */
    command = get_command();

    /* if dynamic allocation failed - return NULL */
    if (command == NULL)
    {
        printf("Fatal error: memory allocation failed!\n");
        return 1;
    }

    /* change matrix using read_mat --> insert 0 to end input */
    float input_a[5] = {1, 2, 3, 4, 0};

    read_mat(MAT_A, input_a);

    float input_b[21] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 0};
    read_mat(MAT_B, input_b);

    float input_c[14] = {9000000, -80, 3, 42937892, 5.4545, 6454.54523, 7000, 1, 2, 3, 4, 5, 6, 0};
    read_mat(MAT_C, input_c);

    float input_d[17] = {12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 0};
    read_mat(MAT_D, input_d);

    float input_e[17] = {-1, -12, -123, -1234, -12345, 1.2345, 12.345, 123.45, 1234.5, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 0};
    read_mat(MAT_E, input_e);

    /* print matrix using print_mat */
    print_mat(MAT_A);
    print_mat(MAT_B);
    print_mat(MAT_C);
    print_mat(MAT_D);
    print_mat(MAT_E);
    print_mat(MAT_F);

    return 0;
}