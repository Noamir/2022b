#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LIMIT 50 /* default limit of chars to get from stdin. if limit is reached - realloc will be made */
#define LINE_LEN 20      /* number of chars in each printed line */
#define INCREAS_BY 2     /* when limit is reached - increase it by this number */

#define NODE_CHARS 10

struct node_def
{
    char *chars; /* chars[NODE_CHARS] */
    struct node_def *next;
};

typedef struct node_def node_t;

/* getChars: get unlimited number of chars from file, return pointer to these chars */
node_t *getChars(FILE *fptr)
{
    int i = 0, limit = DEFAULT_LIMIT;
    node_t *head;
    node_t *tmp_ptr = calloc(1, sizeof(node_t));

    /* allocate DEFAULT_LIMIT size for dynamic chars pointer size */
    node_t *node = calloc(1, sizeof(node_t));

    head = node;

    node->chars = (char *)malloc(limit * sizeof(char));

    /* if dynamic allocation failed - return NULL */
    if (node->chars == NULL)
        return NULL;

    /* insert input to the next space in chars. If chars limit is met - realloc. */
    for (i = 0; (i <= limit) && (*(node->chars + i) = fgetc(fptr)) != EOF; i++)
    {
        node->next = calloc(1, sizeof(node_t));

        /* got to the limit of chars size - increase limit and realloc chars with new limit size */
        if (i == limit - 1)
        {
            limit = INCREAS_BY * limit;
            tmp_ptr->chars = (char *)realloc(node->chars, limit * sizeof(char));

            /* if dynamic allocation failed - return NULL */
            if (tmp_ptr->chars == NULL)
                return NULL;

            node->chars = tmp_ptr->chars;
        }
        node->next->chars = (char *)malloc(limit * sizeof(char));
        node = node->next;
    }
    return head;
}

/* printChars: print all *chars chars in a nice format */
/* special chars to handle for unified printing: \n and \t */
void printChars(node_t *node)
{
    int i = 0, len = 0;

    printf("\n\n===== NICE PRINT =====\n\n");

    while (node != NULL)
    {
        while (*(node->chars + i) != EOF)
        {
            if (*(node->chars + i) == '\n') /* \n is a special char - starts a new line*/
            {
                printf("%c", *(node->chars + i)); /* print char */
                len = 0;                          /* reset len counter to 0 */
                i++;                              /* point to next char in *chars */
            }

            else
            {
                if (len >= LINE_LEN) /* for any other char - first check if line limit has reached LINE_LEN */
                {
                    printf("\n"); /* start a new line */
                    len = 0;      /* reset len counter to 0 */
                }

                if (*(node->chars + i) == '\t') /* \t is a special char */
                {
                    printf("%c", *(node->chars + i)); /* print char */
                    len += (8 - (len % 8));           /* increase len with the space tab takes in line - completes to multiple of 8 spot*/
                    i++;                              /* point to next char in *chars */
                }

                else /* for all other chars */
                {
                    printf("%c", *(node->chars + i)); /* print char */
                    len++;                            /* increase len by 1 */
                    i++;                              /* point to next char in *chars */
                }
            }
        }
        node = node->next;
    }

    printf("\n\n========= END =========\n\n");
}

/* main */
int main(int argc, char **argv)
{
    FILE *fptr;
    char *filePath;
    node_t *head = calloc(1, sizeof(node_t));

    /* validate the input */
    if (argc != 3)
    {
        printf("Usage: %s -f <path_to_file>\n", argv[0]);
        return 0;
    }

    if (strcmp(argv[1], "-f") != 0)
    {
        printf("Usage: %s -f <path_to_file>\n", argv[0]);
        return 0;
    }

    filePath = argv[2];

    fptr = fopen(filePath, "r");

    /* Exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    /* get unlimited number of chars from file into a list */
    head = getChars(fptr);

    printChars(head);

    /* free chars allocation */
    /* free(chars); */
    /* close file */
    /* fclose(fptr); */
    return 0;
}