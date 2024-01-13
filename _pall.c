#include "monty.h"

/**
 * pall - prints all stack
 * @stack: pointer to the pointer to the stack
 * @line_number: the line number currently being read
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_stack = *stack;
	(void) line_number;

	while (tmp_stack)
	{
		printf("%d\n", tmp_stack->n);
		tmp_stack = tmp_stack->next;
	}
}
