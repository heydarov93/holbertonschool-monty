#include "monty.h"

/**
 * print_error - prints formatted string to the stderr
 * @err_code: error code
 *
 * description: stops program with EXIT_FAILURE status
 */

void print_error(int err_code)
{
	switch (err_code)
	{
		case 400:
			fprintf(stderr,
				RED "L%u: usage: push integer\n" COLOR_RESET,
				global.line);
			break;
		case 404:
			fprintf(stderr,
				RED "L%u: unknown instruction %s\n" COLOR_RESET,
				global.line, global.opcode);
			break;
		case 500:
			fprintf(stderr, RED "Error: malloc failed\n" COLOR_RESET);
			break;
	}

	free(global.opcode);
	fclose(global.file);
	free_all_stack();
	exit(EXIT_FAILURE);
}
