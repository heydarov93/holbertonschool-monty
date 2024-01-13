#include "monty.h"

/**
 * pint - prints top stack
 * @stack: pointer to the pointer to the stack
 * @line_number: the line number currently being read
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack == NULL)
	{
		global.error = 204;
		return;
	}

	printf("%d\n", (*stack)->n);
}
