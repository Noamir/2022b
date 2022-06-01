#include "data.h"

/* struct definition for list node */
struct node_def
{
    char chars[NODE_CHARS];
    struct node_def *next;
};



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

    if (head == NULL)
    {
        printf("\nFatal error: memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    /* insert the next char from file to the next index in current list node chars array */
    while ((*(node->chars + i) = fgetc(fptr)) != EOF)
    {
        /* if NODE_CHARS limit is met - create a new node in list, and move on to it */
        if (i == NODE_CHARS - 1)
        {
            node->next = calloc(1, sizeof(node_t));
            if (node->next == NULL)
            {
                printf("\nFatal error: memory allocation failed!\n");
                exit(EXIT_FAILURE);
            }
            node = node->next;
            i = 0; /* new node, chars starts from index 0 */
        }
        else
            i++;
    }
    node->next = NULL; /* need to know where the list ends */
    return head;
}


/** print_list:
Get a list's node to start printing from
Print all nodes chars in a nice format
Special chars to handle for unified printing: '\n' and '\t'
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
            if (*(node->chars + i) == '\n')       /* \n is a special char - starts a new line*/
            {
                printf("%c", *(node->chars + i)); /* print char */
                len = 0;                          /* reset len counter to 0 */
                i++;                              /* point to next char in *chars */
            }

            else
            {
                if (len >= LINE_LEN) /* for any other char - first check if line limit has reached LINE_LEN */
                {
                    printf("\n");    /* start a new line */
                    len = 0;         /* reset len counter to 0 */
                }

                if (*(node->chars + i) == '\t')       /* \t is a special char */
                {
                    printf("%c", *(node->chars + i)); /* print char */
                    len += (8 - (len % 8));           /* increase len with the space tab takes in line - completes to multiple of 8 spot*/
                    i++;                              /* point to next char in *chars */
                }

                else                                  /* for all other chars */
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


/** This program gets a file name from the command line in this format: '-f <path_to_file>'
The file should contain unlimited number of chars.
The program insert the file content into a linked list and prints its content in a nice format to stdout.
**/
int main(int argc, char **argv)
{
    FILE *fptr;
    char *filePath = (char *)malloc(FILE_PATH_LEN * sizeof(char));
    node_t *head = calloc(1, sizeof(node_t));
    node_t *tmp = calloc(1, sizeof(node_t));

    if (filePath == NULL || head == NULL || tmp == NULL)
    {
        printf("\nFatal error: memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    /* validate the command */
    if ((argc != 3) || (strcmp(argv[1], "-f") != 0))
    {
        printf("The command you inserted is not in the right format. Please try again.\nUsage: %s -f <path_to_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* open file */
    filePath = argv[2];
    fptr = fopen(filePath, "r");

    /* exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("Unable to open file: %s\n",  argv[2]);
        printf("Please check the file exists and make sure you have the right previleges.\n");
        exit(EXIT_FAILURE);
    }

    /* get unlimited number of chars from file into a list starts with head node */
    head = build_list(fptr);

    /* print all chars in list in a nice format */
    print_list(head);

    /* free list nodes allocation */
    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    /* close file */
    fclose(fptr);

    return 0;
}