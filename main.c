#include "main.h"

/**
 * read_input - Reads a line of input from the user.
 *
 * Return: A dynamically allocated string containing the user input,
 * or NULL if an error occurs or an empty line is entered.
 */
char *read_input(void)
{
	char *lineptr = NULL;
	size_t bufferSize = 0;
	ssize_t bytesRead = 0;

	if (isatty(STDIN_FILENO))
		printf("$ ");
	fflush(stdout);

	bytesRead = getline(&lineptr, &bufferSize, stdin);

	if (bytesRead == -1)
	{
		free(lineptr);
		lineptr = NULL;
		if (isatty(STDIN_FILENO))
			printf("\n");
		exit(0);
	}

	lineptr[bytesRead - 1] = '\0';

	if (*lineptr == '\0')
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}

/**
 * process_input - Processes the input line by parsing and executing commands.
 * @input: The input string to be processed.
 * @argv: An array of strings containing the command-line arguments.
 * @cmdCount: A pointer to an integer representing the count of executed
 * commands.
 *
 * Return: No return value.
 */
void process_input(char *input, int *cmdCount, char *argv)
{
	char **commands = parse_input(input, argv);

	if (commands != NULL)
	{
		execute_command(commands);
		free_cmds(commands);
	}

	free(input);
	(*cmdCount)++;
}

/**
 * main - entry function for the simple shell
 * @argc: argument count (unused)
 * @argv: argument vector
 *
 * Return: 0 Success
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input;
	int cmdCount = 0;

	while (1)
	{
		input = read_input();

		if (input != NULL)
			process_input(input, &cmdCount, argv[0]);
	}

	return (0);
}
