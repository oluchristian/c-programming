#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int i, j, *ptr;


    printf("Enter a total number of values:\n");
    scanf("%d", &i);
    ptr = (int*)malloc(i * sizeof(int));

    printf("Input %d numbers\n", i);
    for (j = 0; j < i; j++)
    {
        scanf("%d", (ptr+j));
    }
    printf("\n The entered values are:");
    for(j = 0; j < i; j++)
    {
        printf("%d", *(ptr+j));
    }
    free(ptr);
    
}