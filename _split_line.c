#include "monty.h"

int split_line(char **line)
{
	char *token;
	const char *delim = " \t";

	token = strtok(*line, delim);

	if (token == NULL)
		return (-1);

	global.opcode = token;

	token = strtok(NULL, delim);

	if (token != NULL)
		global.value = token;

	return (0);
}
