#include "monty.h"

/**
 * pstr_ - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void pstr_(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * rotl_ - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotl_(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;


	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * rotr_ - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotr_(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}
