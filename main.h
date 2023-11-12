#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#define RANGE 1024
extern char **environ;

void command(char *linestr);
char *_location(char *command_args);
void _exec(char **args);

char *_envpath(const char *str);
void commandfork(char **argstr);

void free_(char **strargs);
int cmpstr(const char *st1, const char *st2);
char *catstr(char *str, char *src);
int strncmp_made(const char *st1, const char *st2, size_t i);

void execute_env(void);
ssize_t _getline(char *buf, size_t size);
char **split_str(char *str, const char *delim);
int lenstr(const char *str);
char *cpystr(char *str, const char *src);
char *_strdup(const char *str);



#endif
