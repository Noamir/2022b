#include "data.h"

/* get_chars: get unlimited number of chars from stdin, return pointer to these chars */
char *get_chars()
{
    int i = 0, limit = DEFAULT_LIMIT;
    char *tmp_ptr;

    /* allocate DEFAULT_LIMIT size for dynamic chars pointer size */
    char *chars = (char *)malloc(limit * sizeof(char));

    /* if dynamic allocation failed - return NULL */
    if (chars == NULL)
    {
        return NULL;
    }

    printf("Hello, Please insert as many chars as you want: \n(to end input click ctrl+d or ctrl+z, depending on your os)\n");

    /* insert input to the next space in chars. If chars limit is met - realloc. */
    for (i = 0; (i <= limit) && (*(chars + i) = getchar()) != EOF; i++)
    {
        /* got to the limit of chars size - increase limit and realloc chars with new limit size */
        if (i == limit - 1)
        {
            limit = INCREAS_BY * limit;
            tmp_ptr = (char *)realloc(chars, limit * sizeof(char));

            /* if dynamic allocation failed - return NULL */
            if (tmp_ptr == NULL)
            {
                return NULL;
            }

            chars = tmp_ptr;
        }
    }
    return chars;
}


/* count_chars: count and return all chars in *chars */
int count_chars(char *chars)
{
    int i = 0;

    while (*(chars + i) != EOF)
    {
        i++;
    }

    return i;
}


/* count_alphanum_chars: count and return all alphanumeric chars in *chars */
int count_alphanum_chars(char *chars)
{
    int counter = 0, i = 0;

    while (*(chars + i) != EOF)
    {
        if (isalnum(*(chars + i)))
        {
            counter++;
        }

        i++;
    }

    return counter;
}


/* print_chars: print all *chars chars in a nice format */
void print_chars(char *chars)
{
    int i = 0, len = 0;

    printf("\n\n===== NICE PRINT =====\n\n");

    while (*(chars + i) != EOF)
    {
        if (*(chars + i) == '\n')       /* got to a new line char - print char (start a new line) and reset len counter to 0 */
        {

            printf("%c", *(chars + i)); /* print char */
            len = 0;                    /* new line - len is 0 */
            i++;                        /* point to next char in *chars */
        }

        else
        {
            if (len == LINE_LEN)        /* got to LINE_LEN limit - start a new line and reset len counter to 0 */
            {
                printf("\n");
                len = 0;
            }

            printf("%c", *(chars + i)); /* print char */
            len++;                      /* increase len */
            i++;                        /* point to next char in *chars */
        }
    }

    printf("\n\n========= END =========\n\n");
}


/* This program gets unlimited number of chars from stdin.
 The program prints to stdout:
 1. The input in a nice format
 2. The count of all chars from stdin
 3. The count of alphanumeric chars from stdin  */

int main(void)
{
    char *chars;
    int counter_all, counter_alphanum;

    /* get unlimited number of chars to chars pointer */
    chars = get_chars();

    if (chars == NULL)
    {
        printf("Fatal error: memory allocation failed!\n");
        return 1;
    }

    /* count all chars from stdin */
    counter_all = count_chars(chars);

    /* count alphanumeric chars from stdin */
    counter_alphanum = count_alphanum_chars(chars);

    /* print input in a nice format */
    print_chars(chars);

    /* print number of total chars and number of alphanumeric chars */
    printf("Number of total chars in input: %d\n", counter_all);
    printf("Number of alphanumeric chars in input: %d\n", counter_alphanum);

    /* free chars allocation */
    free(chars);

    return 0;
}