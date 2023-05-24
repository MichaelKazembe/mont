#include "monty.h"
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
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
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
            return EXIT_FAILURE;
        }

        /* Execute the found instruction */
        instruction.f(&stack, line_number);
    }

    free(line);
    fclose(file);
    free_all(&stack);
    return EXIT_SUCCESS;
}
