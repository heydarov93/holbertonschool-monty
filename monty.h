#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

#define RED "\033[0;31m"
#define COLOR_RESET "\033[0m"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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

/**
 * struct global_s - global struct to use through all files
 * @int_value: integer
 * @value: value from file (str)
 * @line: number of read lines
 * @stack: pointer to the stack
 * @opcode: operation code
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_s
{
	int int_value;
	char *value;
	unsigned int line;
	stack_t *stack;
	char *opcode;
} global_t;

global_t global;

void error(int n, ...);
void _read_file(FILE *stream);
void push(stack_t **stack, unsigned int line_number);
void init_global(void);

#endif
