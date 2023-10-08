#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i = 1;
    char *token;

    for (i = 1; i < argc; i++)
    {
        token = strtok(argv[i], " ");
        while (token != NULL)
        {
            printf("Token: %s\n", token);
            token = strtok(NULL, " ");
        }
    }
    return 0;
}