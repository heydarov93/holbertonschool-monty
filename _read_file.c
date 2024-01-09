#include "monty.h"

/**
 * _read_file - to read file line by line
 * @stream: pointer to the file
 */

void _read_file(FILE *stream)
{
	char *line = NULL;
	size_t n = 0;

	while (getline(&line, &n, stream) != -1)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
}
