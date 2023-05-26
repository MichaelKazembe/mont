#include "monty.h"

/**
 * sub_ - subtracts top ele. of stack from 2nd top ele.
 * @stack: pointer to lists for monty stack
 * @line_number: line num opcode occurs on
 */
void sub_(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sub = 0;
	int i = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	pop_(stack, line_number);

	(*stack)->n = sub;
}

/**
 * mul_ - multiple top ele. of stack y 2nd top ele.
 * @stack: pointer to lists for monty stack
 * @line_number: line num opcode occurs on
 */
void mul_(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(varg.buffer);
		fclose(varg.file);
		free_dlist_int(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		num = (*stack)->n;
		pop_(stack, line_number);
		(*stack)->n *= num;
	}
}

/**
 * div_ - divide top ele. of stack y 2nd top ele.
 * @stack: pointer to lists for monty stack
 * @line_number: line num opcode occurs on
 */
void div_(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(varg.buffer);
		fclose(varg.file);
		free_dlist_int(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(varg.buffer);
		fclose(varg.file);
		free_dlist_int(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = (*stack)->n;
		pop_(stack, line_number);
		(*stack)->n /= i;
	}
}

/**
 * mod_ - mod top ele. of stack y 2nd top ele.
 * @stack: pointer to lists for monty stack
 * @line_number: line num opcode occurs on
 */
void mod_(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(varg.buffer);
		fclose(varg.file);
		free_dlist_int(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(varg.buffer);
		fclose(varg.file);
		free_dlist_int(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = (*stack)->n;
		pop_(stack, line_number);
		(*stack)->n %= i;
	}
}
