#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two numbers
 *
 * @argc: number of arguements
 * @argv: vector of arguements
 *
 * Return: Always 0 (Success)
 */

int main (int argc, char *argv[])
{
int i = 1;
if (argc != 3)
{
    printf("Error\n");
    return 1;
}
else
{
int num1 = atoi(argv[i]);
int num2 = atoi(argv[i+1]);
int mul = num1 * num2;
printf("%d\n", mul);
return (0);
}

}
