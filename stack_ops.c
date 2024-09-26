#include "monty.h"

/**
* push - Pushes an element to the stack.
* @stack: Double pointer to the stack.
* @line_number: The current line number.
* @arg: The argument for the push opcode.
*/
void push(stack_t **stack, unsigned int line_number, char *arg)
{
stack_t *new_node;
int value;

if (arg == NULL || !is_integer(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(arg);
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->next = *stack;
new_node->prev = NULL;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}

/**
* pall - Prints all the values on the stack, starting from the top.
* @stack: Double pointer to the stack.
* @line_number: Line number (unused).
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
* pint - Prints the value at the top of the stack.
* @stack: Double pointer to the stack.
* @line_number: Line number.
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}
