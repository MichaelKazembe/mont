#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int SQ = 1;

int main(int argc, char **argv)
{
    FILE *file_in;
    unsigned int line_number = 0;
    char *line = NULL;
    stack_t *top = NULL;
    instruction_t *instruction = NULL;
    size_t glsize = 0;

    /* check for proper number of arguments */
    if (argc != 2)
    {
        fprintf(stdout, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* open file */
    file_in = fopen(argv[1], "r");
    if (file_in == NULL)
    {
        fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* parse file */
    while (fgets(line, glsize, file_in) != NULL)
    {
        line_number++;
        instruction = parse_line(line);

        if (!(instruction->opcode) || instruction->opcode[0] == '#')
        {
            free(instruction);
            continue;
        }

        if (instruction->f)
            instruction->f(&top, line_number);
        else
        {
            fprintf(stdout, "L%d: unknown instruction %s\n",
                    line_number, instruction->opcode);
            if (top)
                free_stack(top);
            free(instruction);
            fclose(file_in);
            exit(EXIT_FAILURE);
        }

        free(instruction);
    }

    free_stack(top);
    fclose(file_in);
    return 0;
}

