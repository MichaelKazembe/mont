#include "monty.h"
/**
 * f_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    
    varg.lifi = 0; // Set data_format to 0 for stack (LIFO)
}
/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	varg.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *num;

	num = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (num)
	{
		while (num->next)
			num = num->next;
	}
	if (!num)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		num->next = new_node;
		new_node->prev = num;
	}
}
