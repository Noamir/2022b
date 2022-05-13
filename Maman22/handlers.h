#include "mat.h"
void print_mat(mat_t *m);
int whichMat(char *c);
int validateMat(int matIdx);
int validateCommas(char *command);
int validateNull(char *command);
int validateScalar(char *scalar_str);
int validateNumber(char *num_str);
void trimLeadingSpaces(char *c);