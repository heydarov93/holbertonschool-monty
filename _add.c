#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the pointer to the stack
 * @line_number: the line number currently being read
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		global.error = 207;
		return;
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
