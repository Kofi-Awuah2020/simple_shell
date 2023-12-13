#include "main.h"

/**
 * parse_input - Parse the input line into commands.
 *
 * @lineptr: The input line.
 * @input: Input string to be parsed.
 * Return: An array of strings representing the parsed command and arguments,
 * or NULL if an error occurs.
 */
char **parse_input(char *input, char *argv)
{
	char **commands = NULL;

	commands = tokenize(input, " ");

	if (commands == NULL)
		return (NULL);

	if (access(commands[0], X_OK) == -1)
	{
		get_path(&commands[0]);

		if (commands == NULL && access(commands[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: %s: not found\n", argv, commands[0]);
			free_cmds(commands);
			return (NULL);
		}
	}

	return (commands);
}
