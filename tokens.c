#include "shell.h"
/**
 * tokens - divide the string into tokens
 * @string: input string saved in getline
 * Return: pointer to array of tokens
 */
char **tokens(char *string)
{
	char **savingtok = NULL;
	char *token = _strdup(string);
	int i = 0, ntok = 0;
	char *tmp = NULL;

	tmp = string;

	tmp = strtok(tmp, " \n\t");
	while (tmp != NULL)
	{
		ntok++;
		tmp = strtok(NULL, " \n\t");
	}

	savingtok = (char **) malloc((ntok * sizeof(char *) + 1));
	token = strtok(token, " \n\t");
	while (token != NULL)
	{
		savingtok[i] = _strdup(token);
		i++;
		token = strtok(NULL, " \n\t");
	}
	savingtok[ntok + 1] = '\0';


	free(token);
	return (savingtok);
}
