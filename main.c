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
	if (argc != 2)
	{
		fprintf(stderr, RED "USAGE: monty file\n" COLOR_RESET);
		exit(EXIT_FAILURE);
	}

	init_global();

	global.file = fopen(argv[1], "r");

	if (!global.file)
		error(2, "Error: Can't open file ", argv[1]);

	if (_read_execute() == -1)
		exit(EXIT_FAILURE);

	fclose(global.file);
	free_all_stack();

	return (0);
}

/**
 * free_all_stack - frees all stack
 *
 */

void free_all_stack(void)
{
	stack_t *tmp_stack = global.stack;

	while (global.stack)
	{
		tmp_stack = global.stack->next;
		free(global.stack);
		global.stack = tmp_stack;
	}
}
