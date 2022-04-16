#include <stdio.h>
#include <stdlib.h>


#define DEFAULT_LIMIT 50    /* default limit of array size, if limit is reached - realloc will be made */
#define LINE_LEN 20         /* number of chars in each printed line */
#define INCREAS_BY 2        /* when limit is reached - increase it by this number */


int isalnum( int ch );