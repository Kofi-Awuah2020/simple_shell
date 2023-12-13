#include "main.h"

/**
 * get_path - function returns the path of a valid executable file
 * @pathname: command name
 * Return: Void
 */
void get_path(char **pathname)
{
	char *token = NULL, *path = NULL, *path_dir = NULL, *tempStr = NULL;

	if (*pathname == NULL)
		return;
	path_dir = getenv("PATH");
	if (path_dir == NULL)
		return;
	tempStr = strdup(path_dir);
	token = strtok(tempStr, ":");

	while (token != NULL)
	{
		path = malloc(sizeof(char *) * (strlen(*pathname) + strlen(token) + 2));
		if (path == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			free(tempStr);
			return;
		}
		sprintf(path, "%s/%s", token, *pathname);
		if (access(path, X_OK) == 0)
		{
			free(*pathname);
			*pathname = strdup(path);
			free(path);
			free(tempStr);
			return;
		}
		free(path);
		token = strtok(NULL, ":");
	}
	free(tempStr);
}
