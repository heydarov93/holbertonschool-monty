#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the pointer to the stack
 * @line_number: the line number currently being read
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		global.error = 206;
		return;
	}

	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}
