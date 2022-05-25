#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LIMIT 50 /* default limit of chars to get from stdin. if limit is reached - realloc will be made */
#define LINE_LEN 20      /* number of chars in each printed line */
#define INCREAS_BY 2     /* when limit is reached - increase it by this number */

#define NODE_CHARS 10

struct node_def
{
    char chars[NODE_CHARS];
    struct node_def *next;
};

typedef struct node_def node_t;

/** build_list:
Get a file pointer.
Insert unlimited number of chars from the given file into a list.
Each node in the list contains NODE_CHARS number of chars.
Return a pointer to the list's head
**/
node_t *build_list(FILE *fptr)
{
    int i = 0;
    node_t *head, *node;
    head = node = calloc(1, sizeof(node_t));

    /* TODO - handle empty file */
    /* TODO - handle failed calloc */

    /* insert the next char from file to the next index in current list node chars array */
    while ((*(node->chars + i) = fgetc(fptr)) != EOF)
    {   
        /* if NODE_CHARS limit is met - create a new node in list, and move on to it */
        if (i == NODE_CHARS - 1)
        {
            node->next = calloc(1, sizeof(node_t));
            node = node->next;
            i = 0;      /* new node, chars starts from index 0 */
        }
        else
            i++;
    }
    node->next = NULL;  /* need to know where the list ends */
    return head;
}


/** print_list:
Get a list's node to start printing from
Print all nodes chars in a nice format
Special chars to handle for unified printing: \n and \t 
**/
void print_list(node_t *node)
{
    int i = 0, len = 0;

    printf("\n\n===== NICE PRINT =====\n\n");

    /* Go over all list nodes */
    while (node != NULL)
    {
        /* Go over each node and print its contents */
        while (*(node->chars + i) != EOF && (i < NODE_CHARS))
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
        i = 0;
    }
    printf("\n\n========= END =========\n\n");
}


/** This program.... **/
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
    head = build_list(fptr);

    print_list(head);

    /* free chars allocation */
    /* free(chars); */
    /* close file */
    fclose(fptr);
    return 0;
}