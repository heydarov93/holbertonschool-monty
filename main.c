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
	stack_t *ptr_stack, stack;
	//instruction_t instructions[7] = { {"push", push} }

	ptr_stack = &stack;

	if (argc != 2)
	{
		fprintf(stderr, RED "USAGE: monty file\n" COLOR_RESET);
		exit (EXIT_FAILURE);
	}

	init_global();

	ptr_stack->n = global.int_value;
	ptr_stack->prev = NULL;
	ptr_stack->next = NULL;

	global.file = fopen(argv[1], "r");

	if (!global.file)
		error(2, "Error: Can't open file ", argv[1]);

	_read_file();

	fclose(global.file);

	return (0);
}
