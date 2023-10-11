#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int main (int argc, char*argv[])
{
    char *buffer = NULL, *prompt = "$ ";
    int status;
    size_t n;
    ssize_t read;
    bool frm_pipe = false;
    pid_t newProcess;
while (1 && !frm_pipe)
{   
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
        free(buffer);
    }
    /*replace the new line with null terminator*/
    if (buffer[read - 1] == '\n')
        buffer[read - 1] = '\0';

    /**Create a fork */

    newProcess = fork();
    if (newProcess == 0)
    {
        if (execve(buffer, argv, NULL) == -1)
        {
            write(STDOUT_FILENO, "Error (execve)", 14);
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
    
}
free(buffer);
return (0);
}