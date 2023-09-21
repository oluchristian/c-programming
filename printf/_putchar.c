#include "main.h"
/**
 * _putchar - write char c to stdout
 * @c: char to print
 *
 * Return: success (1)
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
