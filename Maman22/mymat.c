#include "mat.h"

mat_t *init_mat(mat_t *m) /* m is pointer to the actual mat address - we make changes on the mat */
{
    int i;

    m->size = MAT_SIZE; /* define mat m size */

    /* initiate all matrix cells to 0 */
    for (i = 0; i < m->size * m->size; i++)
    {
        m->matrix[i] = 0; /* define mat m matrix */
    }

    return m;
}

void print_mat_f(mat_t *m) /* m is local - used to print, no changes made */
{
    int i = 0;
    int j = 0;

    printf("\n\n");
    for (i = 0; i < m->size * m->size; i++, j++)
    {

        if (j == m->size)
        {
            printf("\n");
            j = 0;
        }
        printf("%7.2f  ", m->matrix[i]);
    }
    printf("\n\n");
}

void read_mat_f(mat_t *m, float input[]) /* m is pointer to the actual mat address - we make changes on the mat */
{
    int i;

    /* check 2 conditions:
    1. didn't get to the end of m->matrix which is 16 cells
    2. didn't get to the end of input array

    if one of those ended - finish the insertion!  */

    for (i = 0; (i < (m->size * m->size)) && ((input[i]) != 0); i++)
    {
        m->matrix[i] = input[i];
    }
}

char *get_command()
{
    int limit = 10, i = 0;
    char *tmp_ptr;
    char *command = (char *)malloc(limit * sizeof(char));

    /* menu of possible actions: */
    printf("\nWelcome to the best matrix calculator ever! Here are your commands options:\n");

    printf("\n1. read_mat <MATRIX_NAME>,<value>,<value>,<value>");
    printf("\n2. print_mat <MATRIX_NAME>");
    printf("\n3. add_mat <MATRIX_NAME>,<MATRIX_NAME>,<MATRIX_NAME>");
    printf("\n4. sub_mat <MATRIX_NAME>,<MATRIX_NAME>,<MATRIX_NAME>");
    printf("\n5. mul_mat <MATRIX_NAME>,<MATRIX_NAME>,<MATRIX_NAME>");
    printf("\n6. mul_scalar <MATRIX_NAME>,<scaler value>,<MATRIX_NAME>");
    printf("\n7. trans_mat <MATRIX_NAME>,<MATRIX_NAME>");
    printf("\n8. stop - to finish the plan");

    printf("\n\nEnter desired command, click Enter to execute: \n");

    /* get command chars from stdin to command pointer */
    for (i = 0; (i <= limit) && (*(command + i) = getchar()) != '\n'; i++)
    {
        /* got to the limit of chars size - increase limit and realloc command with new limit size */
        if (i == limit - 1)
        {
            limit = 2 * limit;
            tmp_ptr = (char *)realloc(command, limit * sizeof(char));

            /* if dynamic allocation failed - return NULL */
            if (tmp_ptr == NULL)
            {
                return NULL;
            }

            command = tmp_ptr;
        }
    }

    printf("\nThe full command as string:\n");
    printf("%s\n", command);

    return command;
}

/* validate the first param is a valid matrix name + comma */
int expect_mat(char *params[])
{
    char *mat_name = (char *)malloc(100 * sizeof(char));

    printf("\n\n === DEBUG: inside expect_mat() , params are: %s === \n\n ", params);
    printf("inside expect_mat, params are: %s ", params);

    mat_name = params[0];

    printf("inside expect_mat, mat_name is: %s ", mat_name);

    if ((strcmp(mat_name, "MAT_A") == 0) || (strcmp(mat_name, "MAT_B") == 0) || (strcmp(mat_name, "MAT_C") == 0) || (strcmp(mat_name, "MAT_D") == 0) || (strcmp(mat_name, "MAT_E") == 0) || (strcmp(mat_name, "MAT_F") == 0))
    {
        return 1;
    }
    return 0;
}

int expect_number(char *params[])
{   

    int i = 1; /* param 0 is the mat name, check after for numbers */
    while(params[i] != NULL)
    {
        /* if(params[i] ) */
    }

    return 1;
}

/* read mat expects to get 1 mat name, comma, than a list of real numbers separated by commas  */
int validate_read_mat(char *params[])
{

    printf("\n\n === DEBUG: inside validate_read_mat() , params are: %s === \n\n ", *params);
    /* chack mat name */
    if (expect_mat(*params) == 0)
    {
        printf("Undefined matrix name");
    }

    /* check number - comma - number - comma.... */

    while (*(params) != EOF)
    {
        if (expect_number(params) == 0)
        {
            printf("Argument is not a real number");
        }
        /*         if (expect_comma(params) == 0)
                {
                    printf("Missing comma");
                } */
    }

    return 1;
}

int get_action_num(command_t *c)
{
    printf("\n\n === DEBUG: inside get_action_num() === \n\n ");
    int action_num;
    if (strcmp(c->action, "read_mat") == 0)
    {
        action_num = 0;
    }
    else if (strcmp(c->action, "print_mat") == 0)
    {
        action_num = 1;
    }
    else if (strcmp(c->action, "add_mat") == 0)
    {
        action_num = 2;
    }
    else if (strcmp(c->action, "sub_mat") == 0)
    {
        action_num = 3;
    }
    else if (strcmp(c->action, "mul_mat") == 0)
    {
        action_num = 4;
    }
    else if (strcmp(c->action, "mul_scalar") == 0)
    {
        action_num = 5;
    }
    else if (strcmp(c->action, "trans_mat") == 0)
    {
        action_num = 6;
    }
    else if (strcmp(c->action, "stop") == 0)
    {
        action_num = 7;
    }
    else
    {
        action_num = -1;
    }

    return action_num;
}

command_t *insert_command_str_to_struct(char *c)
{
    int i;
    char *p;
    command_t *command = calloc(1, sizeof(command_t));

    command->action = strtok(c, " ");

    printf("The action name is: %s\n", command->action);

    p = strtok(NULL, ",");

    printf("The params are:\n");
    i = 0;
    while(p != NULL){
        printf("%s, ", p);
        command->params_list[i++] = p;
        p = strtok(NULL, ",");
    }
    
    return command;
}

/* get command and start validating it */

int validate(command_t *c)
{
    enum action
    {
        read_mat,
        print_mat,
        add_mat,
        sub_mat,
        mul_mat,
        mul_scalar,
        trans_mat,
        stop
    };

    /* trimSpaces(c); */

    /*parse first command*/
    int action_num;
    action_num = get_action_num(c);

    /*check what kind of operation was called*/
    switch (action_num)
    {
    case read_mat:
        return validate_read_mat(c->params_list);
    case print_mat:
        return 0;
    case add_mat:
        return 0;
    default:
        printf("\nUndefined command name\n");
        return -1;
    }
}





void initiate_func(command_t *command)
{   

    enum action
    {
        read_mat,
        print_mat,
        add_mat,
        sub_mat,
        mul_mat,
        mul_scalar,
        trans_mat,
        stop
    };

    /* trimSpaces(c); */

    /*parse first command*/
    char *mat_name = command->params_list[0];
    
    int action_num;
    action_num = get_action_num(command);

    /*check what kind of operation was called*/
    switch (action_num)
    {
    case read_mat:
        read_mat(command->params_list[1], )
    case print_mat:
        return 0;
    case add_mat:
        return 0;
    default:
        printf("\nUndefined command name\n");
        return -1;
    }

}






int main()
{
    char *command_str = (char *)malloc(100 * sizeof(char));
    command_t *command = calloc(1, sizeof(command_t));
    
    int action_num;
    char *saveptr;

    

    mat_t *MAT_A = calloc(1, sizeof(mat_t));
    mat_t *MAT_B = calloc(1, sizeof(mat_t));
    mat_t *MAT_C = calloc(1, sizeof(mat_t));
    mat_t *MAT_D = calloc(1, sizeof(mat_t));
    mat_t *MAT_E = calloc(1, sizeof(mat_t));
    mat_t *MAT_F = calloc(1, sizeof(mat_t));

    /* init default mats cells with 0 */
    init_mat(MAT_A);
    init_mat(MAT_B);
    init_mat(MAT_C);
    init_mat(MAT_D);
    init_mat(MAT_E);
    init_mat(MAT_F);

    /* get command for matrix action from stdin */
    command_str = get_command();

    /* if dynamic allocation failed - return NULL */
    if (command_str == NULL)
    {
        printf("Fatal error: memory allocation failed!\n");
        return 1;
    }

    command = insert_command_str_to_struct(command_str);

    /* validate(command); */


    /* initiate relevant command */
    initiate_func(command);





    /*     command->action = strtok(command_str, " ");

        printf("The action name is: %s\n", command->action);

        command->params_list = strtok(NULL, "\n");

        printf("The params list is: %s\n", command->params_list);

        validate(command); */

    /*     action_num = get_action_num(command); */

    /*     switch (action_num)
        {
        case read_mat:
            read_mat_f(command->params_list, 1);
        case print_mat:

            print_mat_f(MAT_A); */
    /*     case add_mat:
            add_mat_f(command->params_list);
        case sub_mat:
            sub_mat_f(command->params_list);
        case mul_mat:
            mul_mat_f(command->params_list);
        case mul_scalar:
            mul_scalar_f(command->params_list);
        case trans_mat:
            trans_mat_f(command->params_list);
        case stop:
            stop_f(); */
    /*  } */

    /*     mat_list = strtok(command, ",");

        printf("The mat names are: %s\n", mat_list); */

    /*     params = strtok(command, ",");
        printf("The params are: %s\n", params); */

    /* change matrix using read_mat --> insert 0 to end input */
    /* float input_a[5] = {1, 2, 3, 4, 0};

    read_mat(MAT_A, input_a);

    float input_b[21] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 0};
    read_mat(MAT_B, input_b);

    float input_c[14] = {9000000, -80, 3, 42937892, 5.4545, 6454.54523, 7000, 1, 2, 3, 4, 5, 6, 0};
    read_mat(MAT_C, input_c);

    float input_d[17] = {12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 0};
    read_mat(MAT_D, input_d);

    float input_e[17] = {-1, -12, -123, -1234, -12345, 1.2345, 12.345, 123.45, 1234.5, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 0};
    read_mat(MAT_E, input_e); */

    /* print matrix using print_mat */
    /* print_mat(MAT_A);
    print_mat(MAT_B);
    print_mat(MAT_C);
    print_mat(MAT_D);
    print_mat(MAT_E);
    print_mat(MAT_F); */

    return 0;
}
