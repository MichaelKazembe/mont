#include "monty.h"

/**
 * main - Entry point for the Monty ByteCode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t opcodes[] = 
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		char *opcode;
		int i;
		int valid_opcode = 0;

		line_number++;
		opcode = strtok(line, " \n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				valid_opcode = 1;
				break;
			}
		}

		if (!valid_opcode)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	return EXIT_SUCCESS;
}
