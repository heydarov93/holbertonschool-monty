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
	char *extension;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	init_global();

	global.file = fopen(argv[1], "r");
	extension = strstr(argv[1], ".m");
	if (
		!global.file ||
		!extension ||
		strcmp(extension, ".m") != 0
	)
	{
		fclose(global.file);
		fprintf(stderr,
			"Error: Can't open file %s\n",
			argv[1]);
		exit(EXIT_FAILURE);
	}

	if (_read_execute() == -1)
		print_error(global.error);

	free_all_stack();
	fclose(global.file);
	return (0);
}

