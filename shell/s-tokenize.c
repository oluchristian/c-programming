#include "shell.h"

char *_getenv(const char *name);
char *strtok(char *str, const char *sep)
{
    char *directory[];
    int i;
    if (sep == NULL)
        return (NULL);
    char *path = _getenv(str);
    for (i = 0; *path != *sep; i++)
    {
        directory[i] = 
    }
}




char *_getenv(const char *name)
{
    extern char **environ
    char **env = environ;
    char *value = NULL;
    if (name == NULL)
        return (NULL);
    while (*env != NULL)
    {
        if (*env == name)
        {
            value = *env;
            return (value);
        }
        env++;
    }
    return (value);
}