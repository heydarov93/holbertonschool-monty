#include "monty.h"

/**
 * push - adds new stack
 * @stack: pointer to the pointer to the stack
 * @line_number: the line number currently being read
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = (stack_t *)malloc(sizeof(stack_t));
	(void) line_number;
	int value;

	if (new_stack == NULL)
	{
		free(new_stack);
		global.error = 500;
		return;
	}
	value = atoi(global.value);
	if (_isvalid_value() == -1 || value < 0)
	{
		global.error = 400;
		free(new_stack);
		return;
	}

	new_stack->n = value;
	new_stack->prev = NULL;
	new_stack->next = *stack;
	*stack = new_stack;
}
