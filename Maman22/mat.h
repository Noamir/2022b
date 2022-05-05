#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>


#define MAT_SIZE 4
#define DEFAULT_BUFFER 5
#define DEFAULT_MAT_VAL 0

enum STATUS
{
    S_SUCCESS,
    S_FAIL_NO_COMMAND,
    S_FAIL_WRONG_PARAMS,
    S_FAIL_MEMORY_ALLOCATION
};

enum COMMAND
{
    CMD_PRINT_MAT,
    CMD_ADD_MAT,
    CMD_SUB_MAT,
    CMD_MUL_MAT,
    CMD_READ_MAT,
    CMD_STOP,
    CMD_UNDEFINED
};

enum MATRIX
{
    E_MAT_A,
    E_MAT_B,
    E_MAT_C,
    E_MAT_D,
    E_MAT_E,
    E_MAT_F,
    MAT_UNDEFINED
};



struct mat_def
{
    int size;                          /* how many rows and cols in mat (for us 4x4) */
    double matrix[MAT_SIZE][MAT_SIZE]; /* floats array, with MAT_SIZE*MAT_SIZE places (for us 4x4) */
};

typedef struct mat_def mat_t;


struct print_mat_def
{
    char *action;
    mat_t *mat;
};

typedef struct print_mat_def print_mat_t;


struct add_mat_def
{
    mat_t *add1;
    mat_t *add2;
    mat_t *result;
};

typedef struct add_mat_def add_mat_t;


struct sub_mat_def
{
    mat_t *sub1;
    mat_t *sub2;
    mat_t *result;
};

typedef struct sub_mat_def sub_mat_t;


struct mul_mat_def
{
    mat_t *mul1;
    mat_t *mul2;
    mat_t *result;
};

typedef struct mul_mat_def mul_mat_t;


struct read_mat_def
{
    mat_t *mat;
    double numbers[MAT_SIZE*MAT_SIZE];
};

typedef struct read_mat_def read_mat_t;
