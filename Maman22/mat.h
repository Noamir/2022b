#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>


#define MAT_SIZE 4


struct mat_def
{
    int size;                           /* how many rows and cols in mat (for us 4x4) */
    float matrix[MAT_SIZE*MAT_SIZE];    /* floats array, with MAT_SIZE*MAT_SIZE places (for us 4x4) */
};

typedef struct mat_def mat_t;



struct param_def
{
    char *param;
};

typedef struct param_def param_t;



struct command_def
{
    char *action;
    char *params_list[];
};

typedef struct command_def command_t;



struct read_mat_def
{
    char *action;
    char *mat_name;
    float input[];
};

typedef struct read_mat_def read_mat_t;



struct print_mat_def
{
    char *action;
    mat_t *mat;
};

typedef struct print_mat_def print_mat_t;


struct add_mat_def
{
    char *action;
    char *mat_a_name;
    char *mat_b_name;
};


