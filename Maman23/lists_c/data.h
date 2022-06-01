#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH_LEN 2048          /* default length of file path chars length, to get from argv */
#define NODE_CHARS 10               /* number of chars in each list node */
#define LINE_LEN 20                 /* number of chars in each printed line */

typedef struct node_def node_t;     /* type of list node */