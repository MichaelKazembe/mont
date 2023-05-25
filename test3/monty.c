#include "monty.h"
global_var var_global;
/**
 * main - main driver func for monty program
 * @ac: int num of args
 * @av: opcode file
 * Return: 0
 */

int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);
	free_dlist_int(stack);
	return (0);
}
