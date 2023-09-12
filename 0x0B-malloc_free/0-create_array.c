#include <stdio.h>
#include <stdlib.h>

char *create_array(unsigned int size, char c);
int main (void)
{
char *buffer;

    buffer = create_array(98, 'H');
    if  (buffer == NULL)
    {
        printf("failed to allocate memory\n");
        return (1);
    }
    simple_print_buffer(buffer, 98);
    free(buffer);
    return (0);
}


char *create_array(unsigned int size, char c)
{
unsigned int i;

for(i = 0; i )
}