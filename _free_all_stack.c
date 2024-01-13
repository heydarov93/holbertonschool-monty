#include "monty.h"

/**
 * free_all_stack - frees all stack
 *
 */

void free_all_stack(void)
{
	stack_t *tmp_stack = global.stack;

	while (global.stack)
	{
		tmp_stack = global.stack->next;
		free(global.stack);
		global.stack = tmp_stack;
	}
}
