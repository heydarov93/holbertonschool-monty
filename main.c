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
	{
		fprintf(stderr,
			RED "Error: Can't open file %s\n" COLOR_RESET,
			argv[1]);
		exit(EXIT_FAILURE);
	}

	if (_read_execute() == -1)
		print_error(global.error);

	free_all_stack();
	fclose(global.file);
	return (0);
}

