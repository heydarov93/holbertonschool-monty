#include "monty.h"

/**
 * main - entry point
 * @argc: number of args
 * @argv: array of values of args (2d)
 *
 * Return: 0 on Success
 */

int main(int argc, char **argv)
{
	FILE *filename;
	stack_t *ptr_stack, stack;

	ptr_stack = &stack;

	if (argc != 2)
		error(1, "USAGE: monty file");

	init_global();

	ptr_stack->n = global.int_value;
	ptr_stack->prev = NULL;
	ptr_stack->next = NULL;

	filename = fopen(argv[1], "r");

	if (!filename)
		error(2, "Error: Can't open file", argv[1]);

	_read_file(filename);

	return (0);
}
