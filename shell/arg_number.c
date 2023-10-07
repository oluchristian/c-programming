#include <stdio.h>

int main(int ac, char **av)
{
    int i = 1; 
    int j;
    while (av[i] != NULL)
    {
        for (j = 0; av[i][j] != '\0'; j++)
        {
            putchar(av[i][j]);
        }
        putchar('\n');
        i++;
    }
    printf("Number of arguments: %d\n", i - 1);
    return (0);
}