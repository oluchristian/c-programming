#include "shell.h"
extern char **environ
char *_getenv(const char *name)
{
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