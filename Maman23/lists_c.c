#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* main */
int main(int argc, char **argv)
{
    FILE *fptr;
    char *filePath, c;

    if (argc != 3)
    {
        printf("Usage: %s -f <path_to_file>\n", argv[0]);
        return 0;
    }

    if(strcmp(argv[1], "-f") != 0)
    {
        printf("Usage: %s -f <path_to_file>\n", argv[0]);
        return 0;
    }


    filePath = argv[2];

    fptr = fopen(filePath, "r");
    if (fptr == NULL)
    {
        printf("Could not open file %s\n", filePath);
        return 0;
    }
    /* Extract characters from file and store in character c */
    for (c = getc(fptr); c != EOF; c = getc(fptr))
        printf("%c", c);

    fclose(fptr);

    return 0;
}