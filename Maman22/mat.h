#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define MAT_SIZE 4

enum STATUS
{
    SUCCESS,
    FAIL_NO_COMMAND,
    FAIL_WRONG_PARAMS
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

struct mat_def
{
    int size;                          /* how many rows and cols in mat (for us 4x4) */
    float matrix[MAT_SIZE * MAT_SIZE]; /* floats array, with MAT_SIZE*MAT_SIZE places (for us 4x4) */
};

typedef struct mat_def mat_t;

struct param_def
{
    char *param;
};

typedef struct param_def param_t;

struct print_mat_def
{
    char *action;
    mat_t *mat;
};

typedef struct print_mat_def print_mat_t;

