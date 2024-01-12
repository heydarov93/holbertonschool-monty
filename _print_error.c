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
	case 204:
		fprintf(stderr,	"L%u: can't pint, stack empty\n",
				global.line);
		break;
	case 205:
		fprintf(stderr,	"L%u: can't pop an empty stack\n",
				global.line);
		break;
	case 206:
		fprintf(stderr,	"L%u: can't swap, stack too short\n",
				global.line);
		break;
	case 207:
		fprintf(stderr,	"L%u: can't add, stack too short\n",
				global.line);
		break;
	case 400:
		fprintf(stderr,	"L%u: usage: push integer\n",
				global.line);
		break;
	case 404:
		fprintf(stderr,	"L%u: unknown instruction %s\n",
				global.line, global.opcode);
		break;
	case 500:
		fprintf(stderr, "Error: malloc failed\n");
		break;
}

	free(global.opcode);
	fclose(global.file);
	free_all_stack();
	exit(EXIT_FAILURE);
}
