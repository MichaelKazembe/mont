#ifndef _MONTY_H
#define _MONTY_H
#define _POSIX_C_SOURCE 200809L

/*Header Files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* Data Structures */
extern int push_args;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_args: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
	FILE *file;
	int push_args;
	char *buffer;
} global_var;

extern global_var var_global;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

/* Monty Functions */
void pall_(stack_t **stack, unsigned int line_number);
void push_(stack_t **stack, unsigned int line_number);
void pint_(stack_t **stack, unsigned int line_number);
void pop_(stack_t **stack, unsigned int line_number);
void swap_(stack_t **stack, unsigned int line_number);
void nop_(stack_t **stack, unsigned int line_number);
void rotl_(stack_t **stack, unsigned int line_number);
void rotr_(stack_t **stack, unsigned int line_number);

/*string ASCII functions*/
void pchar_(stack_t **stack, unsigned int line_number);
void pstr_(stack_t **stack, unsigned int line_number);

/*math functions*/
void sub_(stack_t **stack, unsigned int line_number);
void add_(stack_t **stack, unsigned int line_number);
void mul_(stack_t **stack, unsigned int line_number);
void div_(stack_t **stack, unsigned int line_number);
void mod_(stack_t **stack, unsigned int line_number);

/*Utility functions*/
void free_dlist_int(stack_t *head);
void dob_free1(stack_t **stack);
void dob_free2(stack_t **stack);
int isalpha_(int c);
#endif
