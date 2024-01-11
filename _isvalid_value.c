#include "monty.h"

/**
 * _isvalid_value - checks if value for push is valid
 *
 * Return: 0 on Success, -1 on Failure
 */

int _isvalid_value(void)
{
	int i;
	char *value = global.value;

	if (value[0] == '\0')
		return (-1);

	for (i = 0; value[i] != '\0'; i++)
	{
		if (isdigit(value[i]) == 0)
		{
			return (-1);
		}
	}

	return (0);
}
