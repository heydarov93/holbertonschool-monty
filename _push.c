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
	char sign = '\0';

	if (new_stack == NULL)
	{
		free(new_stack);
		global.error = 500;
		return;
	}

	if (
		global.value[1] &&
		(global.value[0] == '-' || global.value[0] == '+')
	)
	{
		sign = global.value[0];
		global.value[0] = '1';
	}


	if (_isvalid_value() == -1)
	{
		global.error = 400;
		free(new_stack);
		return;
	}

	if (sign != '\0')
		global.value[0] = sign;

	new_stack->n = atoi(global.value);
	new_stack->prev = NULL;
	new_stack->next = *stack;
	if (*stack)
		(*stack)->prev = new_stack;

	*stack = new_stack;
}
