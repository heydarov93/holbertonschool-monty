#include "monty.h"

/**
 * pop - removes element from top of the stack
 * @stack: pointer to the pointer to the stack
 * @line_number: the line number currently being read
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *tmp;

	if (*stack == NULL)
	{
		global.error = 205;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	(*stack)->prev = NULL;
}
