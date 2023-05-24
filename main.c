#include "monty.h"

/* Global variable */
stack_t *stack = NULL;

/**
 * main - Entry point for the Monty program
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments passed to the program
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
        FILE *file;
        char *line = NULL, *opcode, *arg = NULL;
        size_t len = 0;
        unsigned int line_number = 0;
        instruction_t instruction;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                return (EXIT_FAILURE);
        }

        file = fopen(argv[1], "r");
        if (!file)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                return (EXIT_FAILURE);
        }

        while (getline(&line, &len, file) != -1)
        {
                line_number++;

                /* Parse the opcode and optional argument */
                opcode = strtok(line, " \t\n");
                if (opcode == NULL || opcode[0] == '#')
                        continue;
                arg = strtok(NULL, " \t\n");

                /* Search for the opcode in the instruction set */
                instruction = get_instruction(opcode);
                if (instruction.f == NULL)
                {
                        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                        free_all(&stack);
                        free(line);
                        fclose(file);
                        return (EXIT_FAILURE);
                }

                /* Execute the found instruction */
                instruction.f(&stack, line_number, arg);
        }

        free(line);
        fclose(file);
        free_all(&stack);
        return (EXIT_SUCCESS);
}

/**
 * free_all - Frees all nodes in a stack
 * @stack: The stack to free
 */
void free_all(stack_t **stack)
{
        stack_t *current, *next;

        if (stack == NULL || *stack == NULL)
                return;

        current = *stack;
        while (current != NULL)
        {
                next = current->next;
                free(current);
                current = next;
        }
        *stack = NULL;
}

/**
 * get_instruction - Finds the instruction corresponding to a given opcode
 * @opcode: The opcode to search for
 *
 * Return: The instruction corresponding to the opcode, or a null instruction
 * if no corresponding instruction was found.
 */
instruction_t get_instruction(char *opcode)
{
        int i;
        instruction_t null_instruction = {"", NULL};

        if (opcode == NULL)
                return (null_instruction);

        for (i = 0; instructions[i].opcode; i++)
        {
                if (strcmp(instructions[i].opcode, opcode) == 0)
                        return (instructions[i]);
        }
        return (null_instruction);
}
