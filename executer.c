#include "main.h"
/**
 * execute_command - Executes a command with its arguments in a child process.
 * @commands: An array of strings representing the command and its arguments.
 * @argv: An array of strings containing the command-line arguments.
 * @cmdCount: The count of the executed commands.
 *
 * Return: No return value.
 */
void execute_command(char **commands)
{
	pid_t child;
	int status;

	child = fork();

	if (child == -1)
		return;

	if (child == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
			perror("./shell");
	}
	else
	{
		waitpid(child, &status, 0);
	}
}
