#include "monty.h"

/**
 * split_line - splits line into command and value
 * @line: line
 *
 * Return: 0 on success, -1 on failure
 */


int split_line(char **line)
{
	char *token;
	const char *delim = " \t\n";

	token = strtok(*line, delim);

	if (token == NULL)
	{
		return (-1);
	}

	global.opcode = token;

	token = strtok(NULL, delim);

	if (token != NULL && strlen(token) != 0)
		global.value = token;
	else
		global.value = "\0";

	return (0);
}
