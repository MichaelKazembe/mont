#include "monty.h"
/**
 * swap_ - swaps top ele. with 2nd top stack
 * @stack: pointer to lists for monty
 * @line_number: number of line opcode occurs on
 */

void swap_(stack_t **stack, unsigned int line_number)
{
	stack_t *run;
	int temp;

	run = *stack;
	if (run == NULL || run->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = run->n;
	run->n = run->next->n;
	run->next->n = temp;
}

/**
 * add_ - add top ele. with 2nd top stack
 * @stack: pointer to lists for monty
 * @line_number: number of line opcode occurs on
 */

void add_(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0; 
	int i = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	pop_(stack, line_number);

	(*stack)->n = sum;
}

/**
 * nop_ - nop top ele. with 2nd top stack
 * @stack: pointer to lists for monty
 * @line_number: number of line opcode occurs on
 */

void nop_(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * pchar_ - prints the ASCII value of integer
 * @stack: pointer to the top of the stack
 * @line_number: current line index
 *
 */
void pchar_(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(varg.buffer);
		fclose(varg.file);
		free_dlist_int(*stack);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (num > 127 || num < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(varg.buffer);
		fclose(varg.file);
		free_dlist_int(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(num);
	putchar('\n');
}

/**
 * isalpha_ - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int isalpha_(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
