#include "shell.h"

char *get_path(char *command)
{
    char *path, *duplicate_path, *path_token, *file_path;
    size_t command_length, directory_length;
    struct stat buffer;
    path = getenv("PATH");

    if (path)
    {
        /*Duplicates the path*/
        duplicate_path = strdup(path);
        if (duplicate_path)
        {
            /*Calculates the length of the command*/
            command_length = strlen(command);
            /**Tokenize the path to get all directories*/
            path_token = strtok(duplicate_path, ":");

            while (path_token != NULL)
            {
                directory_length = strlen(path_token);
                file_path = malloc(command_length + directory_length + 2);
                if (file_path)
                {
                    strcpy(file_path, path_token);
                    strcat(file_path, "/");
                    strcat(file_path, command);
                    strcat(file_path, "\0");
                    if (stat(file_path, &buffer) == 0)
                    {
                        free(duplicate_path);
                        return (file_path);
                    }
                    free(file_path);
                }
                path_token = strtok(NULL, ":");
            }
            free(duplicate_path);

            if (stat(command, &buffer) == 0)
            {
                return (command);
            }
        }
    }
    return (NULL);
}