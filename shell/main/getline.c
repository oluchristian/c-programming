#include "shell.h"
int main(int argc, char *argv[], char **env_command)
{
    char *buffer = NULL, *prompt = "$ ";
    char *token, *command, *full_path, *exit_token;
    char *arguements[1024];
    int status, argCount = 0;
    size_t n = 0;
    unsigned int i = 0;
    ssize_t read;
    bool frm_pipe = false;
    pid_t newProcess;
    while (1 && !frm_pipe)
    {
        int argCount = 0;
        /**
         * Print a prompt and getline inputs
         */
        write(STDOUT_FILENO, prompt, 2);
        /**Checks if command is from terminal or from program*/
        /**if (isatty(STDIN_FILENO) == 0)
            frm_pipe = true;*/
        /*Reads data from standard input - stdin*/
        read = getline(&buffer, &n, stdin);
        if (read == -1)
        {
            write(STDOUT_FILENO, "Error getline", 13);
            write(STDOUT_FILENO, "\n", 2);
            exit(EXIT_FAILURE);
        }

        /*replace the new line with null terminator*/
        if (buffer[read - 1] == '\n')
            buffer[read - 1] = '\0';

        /**Tokenize*/
        token = strtok(buffer, " ");

        /**Save commands to an array*/

        while (token != NULL)
        {
            arguements[argCount] = token;
            argCount++;
            token = strtok(NULL, " ");
        }

        arguements[argCount] = NULL;

        /**Exit the shell if user enters the exit command*/
        if (s_strcmp(arguements[0], "exit") == 0)
        {
            free(buffer);
            exit(0);
        }
        /**Prints current environment - builtin env*/
        if (s_strcmp(arguements[0], "env") == 0)
        {
            while (env_command[i] != NULL)
            {
                write(STDOUT_FILENO, env_command[i], strlen(env_command[i]));
                write(STDOUT_FILENO, "\n", 2);
                i++;
            }
        }
        /**Create a fork */
        newProcess = fork();
        if (newProcess == 0)
        {
            /*Full path of the command*/
            full_path = get_path(arguements[0]);
            if (execve(full_path, arguements, NULL) == -1)
            {
                perror("error");
                exit(EXIT_FAILURE);
            }
        }
        else if (newProcess == -1)
        {
            write(STDOUT_FILENO, "Error (fork)", 12);
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }
        argCount = 0;
    }
    free(buffer);
    return (0);
}