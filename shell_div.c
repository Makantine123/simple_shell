#include "shell.h"
/**
 * ctrl_d - function that validate ctrl+d key
 * @ret: return getline
 * @string: buffer of line writed
 * Return: int exit status
 */
int ctrl_d(int ret, char *string)
{
	if (ret < 0)
	{
		if (isatty(0) == 1)
			write(1, "\n", 1);
		free(string);
		exit(EXIT_FAILURE);
	}
	else
		return (1);
}

/**
 * fork_process - function that loop and validate the main process
 * @child: id of child generated
 * @string: buffer of line writed
 * @toktok: pointer to array to tokenize lines
 * Return: int
 */
int fork_process(pid_t child, char *string, char **toktok)
{
	int errors = 1;

	if (child == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child == 0)
	{
		toktok = tokens(string);
		if (_path(toktok) == -1)
		{
			return (-1);
		}
		else
			errors++;
	}
	else
	{
		wait(NULL);
	}
	_free(toktok);
	return (0);
}
/**
 * _itoa - converts a number into string
 * @nerrors: Number to cast
 * Return: new pointer with number converted to string
 */
char *_itoa(size_t nerrors)
{
	char base[] = "0123456789";
	char *newstr;
	unsigned int len = 0;
	int number = nerrors;

	for (len = 0; nerrors > 0; len++)
	{
		nerrors = nerrors / 10;
	}

	newstr = malloc(sizeof(char) * len);
	if (newstr == NULL)
		return (NULL);
	newstr[len] = '\0';
	do {
		newstr[--len] = base[number % 10];
		number /= 10;
	} while (number != 0);
	return (newstr);
}
/**
 * validate_input - function that prints error message
 * @string: buffer of line writed
 * @name: name of program
 * @errors: counter of execute lines
 * Return: Nothing
 */
void validate_input(char **string, char *name, int errors)
{
	char *nstr = _itoa(errors);

	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, nstr, _strlen(nstr));
	write(2, ": ", 2);
	write(2, *string, _strlen(*string));
	write(2, ": not found\n", 12);
	free(nstr);
}
