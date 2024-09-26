#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the stack.
 * @line_number: Line number (unused).
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * is_integer - Checks if a string represents a valid integer.
 * @str: The string to check.
 * 
 * Return: 1 if the string is a valid integer, otherwise 0.
 */
int is_integer(char *str)
{
    if (str == NULL || *str == '\0')
        return (0);

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return (0);
        str++;
    }

    return (1);
}
