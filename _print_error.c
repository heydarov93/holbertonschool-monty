#include "monty.h"

void error(int n, ...)
{
	va_list msgs;
	int i;
	char *msg;

	va_start(msgs, n);

	for (i = 0; i < n; i++)
	{
		msg = va_arg(msgs, char *);
		if (i != n - 1)
			fprintf(stderr, RED "%s " COLOR_RESET, msg);
		else
			fprintf(stderr, RED "%s\n" COLOR_RESET, msg);
	}

	va_end(msgs);
	exit(EXIT_FAILURE);
}
