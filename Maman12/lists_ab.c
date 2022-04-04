#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 50 /* default size of array, if limit is reached - realloc will be made */
#define LINE_LEN 20     /* number of chars in each printed line */

int main()
{
    int isalpha(int ch);

    int *chars = (int *)malloc(DEFAULT_SIZE * sizeof(int)); /* first size of dynamic array - DEFAULT_SIZE */

    int length = DEFAULT_SIZE; /* chars length */

    int i, j = 0;

    int counter_all = 0, counter_alpha = 0; /* counter for all chars and counter for alphanumeric chars */

    printf("Please enter as many chars as you want:\n");

    /* insert input to chars dynamic array. If chars limit is met - realloc. */
    for (i = 0; (i < length) && (chars[i] = getchar()) != EOF; i++)
    {
        if (i == length - 2) /* got to the end of chars length - realloc more space and increase length */
        {
            chars = (int *)realloc(chars, 2 * length * sizeof(int));
            length = 2 * length;
        }

        if (isalpha(chars[i]))
        {
            counter_alpha++;
        }
    }

    /* now we have all input in array */
    counter_all = i;

    /* print nicely */
    printf("\n\nNice printing: \n\n");

    for (i = 0; i < counter_all; i++, j++) /* go over all array */
    {
        if (j == LINE_LEN) /* if got to line limit - start a new line */
        {
            j = 0;
            printf("\n");
        }

        printf("%c", chars[i]); /* print char */
    }

    printf("\n\n"); /* for clear output */

    printf("Number of total chars in input: %d\n", counter_all);
    printf("Number of alphanumeric chars in input: %d\n", counter_alpha);

    /* int ch;
    int i = 0; */

    /* char *chars_list = NULL; */ /* declare a pointer, and initialize to NULL */

    /* insert input to an array with dynamic number of arguments */
    /*  while ((ch = getchar()) != EOF)
     { */

    /* re-allocate space in array, and save there the char */
    /* chars_list = (char *)realloc(chars_list, counter_all * sizeof(char));
    chars_list[counter_all] = ch; */
    /* } */

    /* count */
    /* counter_all++;
    if (isalpha(ch))
    {
        counter_alpha++;
    }

    printf("counter all : %d\n", counter_all);
    printf("counter alpha : %d\n", counter_alpha); */

    /* nice print of the input */
    /* for (i = 0; i <= counter_all; i++)
    {
        printf("%c\n", chars_list[i]);
    } */

    /* free chars_list */
    /* free(chars_list); */ /* de-allocate */

    return 0;
}