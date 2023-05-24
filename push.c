#include "monty.h"

/* Definition of push and pall functions */

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head node of the stack
 * @line_number: The line number currently being executed in the bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
        char *arg = strtok(NULL, " \t\n");
        int n;

        if (arg == NULL || !is_integer(arg))
        {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free_all(stack);
                exit(EXIT_FAILURE);
        }

        n = atoi(arg);
        if (!add_node(stack, n))
        {
                fprintf(stderr, "Error: malloc failed\n");
                free_all(stack);
                exit(EXIT_FAILURE);
        }
}
