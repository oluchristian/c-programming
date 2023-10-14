#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
char *_getenv(const char *name);
int strcmp(const char *s1, const char *s2);
char *strtok(char *str, const char *sep);
#endif