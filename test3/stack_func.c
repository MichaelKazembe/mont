#include "monty.h"
/**
 * push_ - pushes integer to a stack
 * @stack: linked lists 
 * @line_number: line num opcode occurs on
 */
void push_(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = varg.push_args;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * pall_ - print all funcs
 * @stack: pointer to linked list
 * @line_number: line num opcode occurs on
 */
void pall_(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *run;

	run = *stack;
	while (run != NULL)
	{
		printf("%d\n", run->n);
		run = run->next;
	}
}

/**
 * _pint - print integer a top of stack
 * @stack: pointer to linked list 
 * @line_number: line num opcode occurs on
 *
 */
void pint_(stack_t **stack, unsigned int line_number)
{
	stack_t *run;

	run = *stack;
	if (run == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", run->n);
}

/**
 * pop_ - remove element from a list
 *@stack: pointer to first node
 *@line_number: integer
 *Return: void
 */
void pop_(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlist_int - frees a list
 * @head: pointer to the first node
 *
 */
void free_dlist_int(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
