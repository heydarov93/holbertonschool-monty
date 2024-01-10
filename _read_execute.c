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
		trimmed_line = strdup(strtok(line, "\n"));
		free(line);

		split_line(&trimmed_line);

		if (strcmp(global.value, "\0") != 0)
			global.int_value = atoi(global.value);

		if (_execute() == -1)
		{
			fprintf(stderr,
				RED "L%u: unknown instruction %s\n" COLOR_RESET,
				global.line, global.opcode);
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

int _execute(void)
{
	int i;
	instruction_t commands[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};

	for (i = 0; commands[i].opcode; i++)
	{
		if (strcmp(commands[i].opcode, global.opcode) == 0)
		{
			commands[i].f(&global.stack, global.line);
			break;
		}
	}

	if (commands[i].opcode == NULL)
		return (-1);

	return (0);
}
