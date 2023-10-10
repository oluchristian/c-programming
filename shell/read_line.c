#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int ac, char**argv)
{
char *prompt = "$ ";
char *buffer = NULL;
size_t n = 0;
int i;
ssize_t readLine;
pid_t newProcess;
int status;
/**
 * variables to Tokenize the input
 */
char *token;
char *args[50];
int j = 0;
int a = 0;

while (1)
{
/**
 * Print a prompt and getline inputs
 */
printf("%s", prompt);
if (readLine == -1)
{
    free(buffer);
    printf("\n");
    break;
}
else
{
/**
 * Change new line to null terminating char
 */
    for (i = 0; i < readLine; i++)
    {
        if (buffer[i] == '\n')
        buffer[i] = '\0';
    }
}
/**
 * Tokenize the input
 */
token = strtok(buffer, " ");
while (token != NULL)
{
args[j] = token;
token = strtok(NULL, " ");
j++;
}
args[j] = NULL;

newProcess = fork();
        if (newProcess == 0)
        {
            if (execve(args[0], args, NULL) == -1)
            {
                perror("Error executing command");
                a = 0;
                while (args[a] != NULL)
                {
                 args[a] = NULL;
                 a++;
                }
                continue; // Return to the beginning of the while loop
            }
        }
        else if (newProcess > 0)
        {
            // Wait for the child process to complete
            wait(&status);
        }
        else
        {
            
            perror("Error forking");
        }
// Free the buffer after tokenization
free(buffer);
}
}
