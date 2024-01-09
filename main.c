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

	if (argc != 2)
		error(1, "USAGE: monty file");

	filename = fopen(argv[1], "r");

	if (!filename)
		error(2, "Error: Can't open file", argv[1]);

	_read_file(filename);
	return (0);
}
