#include "monty.h"

/**
 * _read_execute - reads file line by line and executes
 *
 * Return: 0 on success, -1 on failure
 */

int _read_execute(void)
{
	char *line = NULL, *trimmed_line;
	size_t n = 0;

	while (getline(&line, &n, global.file) != -1)
	{
		global.line++;
		trimmed_line = strdup(line);
		free(line);

		if (split_line(&trimmed_line) == -1)
		{
			free(trimmed_line);
			line = NULL;
			continue;
		}

		_execute();

		if (global.error != 200)
		{
			global.opcode = strdup(strtok(trimmed_line, " \n\t"));
			free(trimmed_line);
			return (-1);
		}

		free(trimmed_line);
		line = NULL;
	}

	free(line);
	return (0);
}

/**
 * _execute - executes function based on opcode
 *
 * Return: 0 on success, -1 on failure
 */

void _execute(void)
{
	int i;
	instruction_t commands[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {NULL, NULL}
	};

	for (i = 0; commands[i].opcode; i++)
	{
		if (strcmp(commands[i].opcode, global.opcode) == 0)
		{
			commands[i].f(&global.stack, global.line);
			return;
		}
	}

	if (commands[i].opcode == NULL)
		global.error = 404;
}
