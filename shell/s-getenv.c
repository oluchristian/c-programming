#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name);

int main(void) {
    char *variableName = "PATH"; // Change this to the environment variable you want to test
    char *value = _getenv(variableName);

    if (value != NULL) {
        printf("%s=%s\n", variableName, value);
    } else {
        printf("%s not found in the environment.\n", variableName);
    }

    return 0;
}

char *_getenv(const char *name)
{
    extern char **environ;
    char **env = environ;
    char *value = NULL;
    char *env_name;
    if (name == NULL)
        return (NULL);
    while (*env != NULL)
    {
        env_name = *env;
        if (strcmp(env_name, name) == 0)
        {
            printf("Found %s in the environment: %s\n", name, env_name);
            value = strchr(env_name, '='); // Find the value part after '='
            if (value != NULL) {
                value++; // Move past '='
            }
            return value;
        }
        env++;
    }
    return (value);
}

