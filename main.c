#include "monty.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, USAGE);
        exit(EXIT_FAILURE);
    }

    char *filepath = argv[1];

    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filepath);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        /* Extract the opcode and argument from the line */
        // ...

        /* Execute the instruction corresponding to the opcode */
        // ...
    }

    free(line);
    fclose(file);
    return 0;
}
