#include "monty.h"

/**
 * init_global - initializes global struct
 */

void init_global(void)
{
	global.value = "hello world";
	global.int_value = 5500;
	global.line = 0;
	global.stack = NULL;
	global.opcode = NULL;
}
