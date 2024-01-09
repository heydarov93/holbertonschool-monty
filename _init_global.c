#include "monty.h"

/**
 * init_global - initializes global struct
 */

void init_global(void)
{
	global.value = "\0";
	global.int_value = 0;
	global.line = 0;
	global.stack = NULL;
	global.opcode = NULL;
}
