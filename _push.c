#include "monty.h"

/**
 * push - prints all stack
 * @stack: pointer to the pointer to the stack
 * @line_number: the line number currently being read
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = (stack_t *)malloc(sizeof(stack_t));
	(void) line_number;

	if (new_stack == NULL)
	{
		free(new_stack);
		global.error = 500;
		return;
	}

	if (_isvalid_value() == -1)
	{
		global.error = 400;
		free(new_stack);
		return;
	}

	new_stack->n = atoi(global.value);
	new_stack->prev = NULL;
	new_stack->next = *stack;
	*stack = new_stack;
}
