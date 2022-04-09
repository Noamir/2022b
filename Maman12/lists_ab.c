#include "data.h"

int main()
{
    int *chars = malloc(DEFAULT_SIZE * sizeof(int));    /* allocate DEFAULT_SIZE size for dynamic array */

    int length = DEFAULT_SIZE;                          /* chars length */

    int i, j = 0;

    int counter_all = 0, counter_alpha = 0;             /* counter for all chars and counter for alphanumeric chars */

    printf("Please enter as many chars as you want:\n");

    /* insert input to chars dynamic array. If chars limit is met - realloc. */
    for (i = 0; (i < length) && (chars[i] = getchar()) != EOF; i++)
    {
        if (i == length - 2) /* got to the end of chars length - realloc more space and increase length */
        {
            chars = realloc(chars, 2 * length * sizeof(int));
            length = 2 * length;
        }

        if (isalnum(chars[i]))
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
        if (chars[i] == "\n")
            j = 0;         /* reset lines counter */
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

    return 0;
}