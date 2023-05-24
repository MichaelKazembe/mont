#include "monty.h"

/* Helper functions */

/**
 * is_integer - Checks if a string is an integer
 * @str: The string to check
 *
 * Return: 1 if the string is an integer, 0 otherwise
 */
int is_integer(char *str)
{
        int i, len;

        if (str == NULL || *str == '\0' || isspace(*str))
                return (0);

        len = strlen(str);

        for (i = 0; i < len; i++)
        {
                if (i == 0 && str[i] == '-')
                        continue;
                if (!isdigit(str[i]))
                        return (0);
        }

        return (1);
}
/**
 * add_node - Adds a new node to the head of a stack
 * @stack: Double pointer to the head node of the stack
 * @n: The integer value to add to the new node
 *
 * Return: A pointer to the new node on success, or NULL on failure
 */
stack_t *add_node(stack_t **stack, int n)
{
        stack_t *new_node = malloc(sizeof(stack_t));

        if (new_node == NULL)
                return (NULL);

        new_node->n = n;
        new_node->prev = NULL;
        new_node->next = *stack;

        if (*stack != NULL)
                (*stack)->prev = new_node;

        *stack = new_node;
        return (new_node);
}

/**
 * free_all - Frees all nodes in the stack and resets the stack pointer to NULL
 * @stack: Double pointer to the head node of the stack
 */
void free_all(stack_t **stack)
{
    stack_t *current = *stack, *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}
 
