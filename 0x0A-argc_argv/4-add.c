#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int i, sum = 0;

    if (argc == 0)
    {
        printf("0\n");
         
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
            int num = atoi(argv[i]);
            if (num == 0)
            {
                printf("Error\n");
                return (1);
            }
            sum = num + sum;
        }

        printf("%d\n", sum);
        return (0);
    }
}
