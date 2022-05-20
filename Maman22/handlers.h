#include "mat.h"

typedef struct print_mat_def print_mat_t;
typedef struct add_mat_def add_mat_t;
typedef struct sub_mat_def sub_mat_t;
typedef struct mul_mat_def mul_mat_t;
typedef struct mul_scalar_def mul_scalar_t;
typedef struct read_mat_def read_mat_t;
typedef struct trans_mat_def trans_mat_t;

void printMat(mat_t *m);
void statusHandler(int status);
int whichMat(char *c);
int validateMat(int matIdx);
int validateCommas(char *command);
int validateNull(char *command);
int validateScalar(char *scalar_str);
int validateNumber(char *num_str);
void trimLeadingSpaces(char *c);