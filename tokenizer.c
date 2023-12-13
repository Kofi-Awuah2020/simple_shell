#include "main.h"
/**
 * tokenize - function returns an array of string based on given delimiter
 * @str: string to be tokenized
 * @delim: delimiter seperating the substrings
 * Return: A NULL terminated  array of strings
 */
char **tokenize(char *str, const char *delim)
{
	char **array_token = NULL, *temp_str = NULL, *token = NULL;
	size_t x = 0, numTokens = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	if (delim == NULL)
		delim = " \t"; /* If delim is NULL assume space and tabs as delim */
	temp_str = strdup(str); /* Tokenize the input string */
	token = strtok(temp_str, delim); /* Store first token */
	while (token != NULL)
	{
		++numTokens;
		token = strtok(NULL, delim);
	}
	free(temp_str);
	if (numTokens > 0)
	{
		array_token = malloc(sizeof(char *) * (numTokens + 1));
		if (array_token == NULL)
			exit(EXIT_FAILURE);
		token = strtok(str, delim);
		while (token != NULL)
		{
			array_token[x++] = strdup(token);
			token = strtok(NULL, delim);
		}
		array_token[x] = NULL;
	}
	return (array_token);
}
