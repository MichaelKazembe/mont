#include "monty.h"

/**
 * pstr_ - mod top ele. with 2nd top stack
 * @stack: pointer to lists for monty
 * @line_number: number of line opcode occurs on
 */
void pstr_(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0;

	(void)line_number;


	while (tmp)
	{
		num = temp->n;
		if (c == 0 || isalpha_(c) == 0)
			break;
		putchar(c);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * rotl_ - mod top ele. with 2nd top stack
 * @stack: pointer to lists for monty
 * @line_number: number of line opcode occurs on
 */
void rotl_(stack_t **stack, unsigned int line_number)
{
	stack_t *run = *stack;


	int num = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	num = run->n;

	while (run->next)
	{
		run = run->next;
		run->prev->n = run->n;
	}

	run->n = num;
}

/**
 * rotr_ - mod top ele. with 2nd top stack
 * @stack: pointer to lists for monty
 * @line_number: number of line opcode occurs on
 */
void rotr_(stack_t **stack, unsigned int line_number)
{
	stack_t *run = *stack;

	int num = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (run->next)
		run = run->next;

	num = run->n;

	while (run->prev)
	{
		run = run->prev;
		run->next->n = run->n;
	}

	run->n = aux1num;
}
