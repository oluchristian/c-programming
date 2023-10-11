#include <stdbool.h>
#include <unistd.h>
int main (int argc, char*argv[])
{
    char *buffer = NULL, *prompt = "$ ";
    size_t n;
    ssize_t read;
    bool frm_pipe = false;
    pid_t newProcess;
while (1 && !frm_pipe)
{   
    /**Checks if command is from terminal or from program*/ 
    if (isatty(STDIN_FILENO) == 0)
        frm_pipe = true
    /*Reads data from standard input - stdin*/
    read = getline(&buffer, &n, stdin);
    if (read == -1)
    {
        perror("Error getline");
        free(buffer);
    }
    /*replace the new line with null terminator*/
    if (buffer[read - 1] == '\n')
        buffer[read - 1] = '\0';

    /**Create a fork */

    newProcess = fork();
    if (newProcess == 0)
    {
        execve(buffer, );
    }
    else if (newProcess == -1)
    {
        perror("Error (fork)");
        exit(EXIT_FAILURE);
    }
    else
    {
        perror("Error (wait)");
        exit(EXIT_FAILURE);
    }
    
}
}