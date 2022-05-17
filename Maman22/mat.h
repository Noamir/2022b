#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define MAT_SIZE 4
#define DEFAULT_BUFFER 5
#define DEFAULT_MAT_VAL 0
#define NUM_OF_MATS 6

int isspace(int ch);

enum STATUS
{
    S_SUCCESS,
    S_FAIL_NO_COMMAND,
    S_FAIL_NO_MAT,
    S_FAIL_NOT_A_REAL_NUMBER,
    S_FAIL_NOT_A_SCALAR,
    S_FAIL_EXTRA_TEXT,
    S_FAIL_MISSING_ARGS,
    S_FAIL_ILLEGAL_COMMA,
    S_FAIL_MISSING_COMMA,
    S_FAIL_MULTIPLE_COMMAS,
    S_FAIL_NOT_SCALAR,
    S_FAIL_EOF,
    S_FAIL_NO_SPACE,
    S_FAIL_MEMORY_ALLOCATION
};

enum COMMAND
{
    CMD_PRINT_MAT,
    CMD_ADD_MAT,
    CMD_SUB_MAT,
    CMD_MUL_MAT,
    CMD_READ_MAT,
    CMD_MUL_SCALAR,
    CMD_TRANS_MAT,
    CMD_STOP,
    CMD_EOF,
    CMD_NO_SPACE,
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
    MAT_NULL,
    MAT_UNDEFINED
};

struct mat_def
{
    int size;                         
    double matrix[MAT_SIZE][MAT_SIZE]; 
};

typedef struct mat_def mat_t;

int handlePrint(mat_t *all[], char *c);
int handleAdd(mat_t *all[], char *c);
int handleSub(mat_t *all[], char *c);
int handleMul(mat_t *all[], char *c);
int handleRead(mat_t *all[], char *c);
int handleMulScalar(mat_t *all[], char *c);
int handleTrans(mat_t *all[], char *c);