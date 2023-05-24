#include "monty.h"

/**
 * pall - Prints all elements of a stack
 * @stack: Pointer to the head node of the stack
 */
void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
