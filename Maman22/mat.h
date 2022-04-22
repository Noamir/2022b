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

typedef struct mat_def mat;