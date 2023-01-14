#include "shell.h"
/**
 * _free - frees a double pointer
 * @string: pointer to array to free in heap memory
 * Return: void
 */
void _free(char **string)
{
	size_t i = 0;

	if (string == NULL)
		return;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}
