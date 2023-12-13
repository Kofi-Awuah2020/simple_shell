#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


char **tokenize(char *str, const char *delim);
void free_cmds(char **cmds);
extern char **environ;
void get_path(char **pathname);
char **parse_input(char *input, char *argv);
void execute_command(char **commands);
char *read_input(void);
void process_input(char *input, int *cmdCount, char *argv);

#endif
