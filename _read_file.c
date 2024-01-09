#include "monty.h"

/**
 * _read_file - to read file line by line
 * 
 * Return: 0 on success, -1 on failure
 */

int _read_file()
{
	char *line = NULL, *trimmed_line;
	size_t n = 0;

	while (getline(&line, &n, global.file) != -1)
	{
		global.line++;
		trimmed_line = strdup(strtok(line, "\n"));
		free(line);

		split_line(&trimmed_line);
		free(trimmed_line);
		line = NULL;
	}

	free(line);
	return (0);
}
