#include "main.h"

/**
 * free_cmds - function frees sommands recieved by the getline function
 * @cmds: Pointer to an array of commands recieved from Stdin
 *
 * Return: Void
 */
void free_cmds(char **cmds)
{
	int x;

	for (x = 0; cmds[x] != NULL; x++)
	{
		free(cmds[x]);
		cmds[x] = NULL;
	}
	free(cmds);
}
