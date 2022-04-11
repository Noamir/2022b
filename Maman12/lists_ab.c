#include "data.h"

/* get unlimited number of chars from stdin to *chars pointer */
int *get_text(int *chars)
{
    int i = 0;
    int limit = DEFAULT_SIZE; /* chars length limit */

    printf("Please enter as many chars as you want:\n");

    /* insert input to chars dynamic array. If chars limit is met - realloc. */
    for (i = 0; (i <= limit) && (*(chars + i) = getchar()) != EOF; i++)
    {
        /* got to the limit of chars length - realloc more space and increase limit */
        if (i == limit - 1)
        {
            limit = 2 * limit;
            chars = (int *)realloc(chars, limit * sizeof(int));
        }
    }

    return chars; /* if realloc failed, retirns NULL. checking in main - if NULL exist with error */
}

/* count all chars in *chars */
int count_chars(int *chars)
{
    int i = 0;

    while (*(chars + i) != EOF)
    {
        i++;
    }

    return i;
}

/* count all alphanumeric chars in *chars */
int count_alphanum_chars(int *chars)
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

/* print *chars txt nicely */
void print_text(int *chars)
{
    int i = 0, j = 0;

    printf("\n\n===== NICE PRINT =====\n\n");

    while (*(chars + i) != EOF)
    {
        if (*(chars + i) == (int)'\n')
            j = 0;         /* reset lines counter */
        if (j == LINE_LEN) /* if got to line limit - start a new line */
        {
            j = 0;
            printf("\n");
        }

        printf("%c", *(chars + i)); /* print char */

        i++;
        j++;
    }

    printf("\n\n======================\n\n");
}


/* This program gets unlimited number of chars from stdin. 
 The program prints to stdout:
 1. The input in a nice format
 2. The count of all chars from stdin
 3. The count of alphanumeric chars from stdin  */

int main(void)
{
    int *chars, counter_all, counter_alphanum;

    /* allocate DEFAULT_SIZE size for dynamic chars size */
    chars = (int *)malloc(DEFAULT_SIZE * sizeof(int)); 

    /* check if dynamic allocation succeeded */
    if (chars == NULL)
    {
        printf("malloc failed!");
        return 1;
    }

    /* get unlimited number of chars to chars array */
    chars = get_text(chars); 


    /* check if dynamic allocation succeeded */
    if (chars == NULL)
    {
        printf("realloc failed!");
        return 1;
    }

    /* count all chars from stdin */
    counter_all = count_chars(chars); 

    /* count alphanumeric chars from stdin */
    counter_alphanum = count_alphanum_chars(chars); 

    /* print input in a nice format */
    print_text(chars); 

    /* print number of total chars and number of alphanumeric chars */
    printf("Number of total chars in input: %d\n", counter_all);
    printf("Number of alphanumeric chars in input: %d\n", counter_alphanum);

    /* free chars allocation */
    free(chars);

    return 0;
}