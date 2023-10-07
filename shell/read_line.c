#include <stdio.h>

int main(int ac, char**argv)
{
    char *prompt = "myShell $ ";
    char *linep;
    size_t n = 0;
    printf("%s", prompt);
    getline(&linep, &n, stdin);
    printf("%s\n", linep);
    free(lineptr);
    return (0);
}
