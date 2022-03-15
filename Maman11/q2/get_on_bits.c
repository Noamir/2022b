/* get_on_bits: get binary number, return the number of on bits (1) in number */

int get_on_bits(int number)
{
    int counter = 0;

    /* go over number bits */
    while (number > 0)
    {
        /* check number's right bit. if bit is 1 - count, if 0 don't */
        if ((number & 1) == 1)
            counter++;

        /* shift right after every check to go over all bits */
        number = number >> 1;
    }

    return counter;
}