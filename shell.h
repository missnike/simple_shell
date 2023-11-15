fndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
#define MAX_INPUT 1024


void _environment(void);
void _prompt(void);
char *get_env(const char *var_name);
char *find_full_path(char *cmd);
ssize_t my_getline(char **line, size_t *len, FILE *stream);

void _directory(char *user_path);
char *_strtrim(char *str);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
int execute_(char *command_with_args);
void execute_child(char *command, char *args[]);

#endif
