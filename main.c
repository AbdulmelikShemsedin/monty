#include "monty.h"

/**
 * free_stack - Frees the memory allocated for the stack.
 * @stack: The stack to free.
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

/**
 * execute_opcode - Executes the given opcode by matching it to the correct function.
 * @stack: Pointer to the stack.
 * @opcode: The opcode to execute.
 * @arg: The argument for the opcode (if any).
 * @line_number: The current line number in the bytecode file.
 */
void execute_opcode(stack_t **stack, char *opcode, char *arg, unsigned int line_number)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };
    int i = 0;

    while (instructions[i].opcode)
    {
        if (strcmp(instructions[i].opcode, opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode, *arg;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#') /* Skip comments or empty lines */
            continue;
        arg = strtok(NULL, " \t\n");
        
        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, line_number, arg);
        }
        else
        {
            execute_opcode(&stack, opcode, arg, line_number);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);

    return 0;
}

