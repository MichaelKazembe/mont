#include "monty.h"
/**
 * read_file - reads a bytecode file & runs cmds
 * @filename: pathname to a file
 * @stack: pointer to top of stack
 */
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func st;
	int check;
	int readd;


	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((readd = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parse_line_(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		st = get_opcod_func(line);
		if (st == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		st(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_opcod_func -  checks opcode & returns the correct func
 * @str: the actual opcode
 * Return: returns a funcs, or NULL on failure
 */
instruct_func get_opcod_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", push_},
		{"pall", pall_},
		{"pint", pint_},
		{"pop", pop_},
		{"swap", swap_},
		{"add", add_},
		{"nop", nop_},
		{"sub", sub_},
		{"mul", mul_},
		{"div", div_},
		{"mod", mod_},
		{"pchar", pchar_},
		{"pstr", pstr_},
		{"rotl", rotl_},
		{"rotr", rotr_},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * is_integer - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int is_integer(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_line_ - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode or null on failure
 */
char *parse_line_(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *push, *arg;
	(void)stack;

	push = "push";
	opcode = strtok(line, "\n ");
	if (opcode == NULL)
		return (NULL);

	if (strcmp(opcode, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (is_integer(arg) == 1 && arg != NULL)
		{
			var_global.push_args = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}
