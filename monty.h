#ifndef _MONTY_H
#define _MONTY_H
#define USAGE "USAGE: monty file\n"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* Data structures */

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element of the stack (or queue)
 * @next: Pointer to the next element of the stack (or queue)
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack);

int is_integer(char *str);
stack_t *add_node(stack_t **stack, int n);
void free_all(stack_t **stack);
instruction_t get_instruction(char *opcode);

#endif /* _MONTY_H */
