#include <stdio.h>


#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
 dog_t *new_dog(char *name, float age, char *owner);
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    return (0);
}

dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *my_dog = malloc(sizeof(dog_t));
    if (my_dog != NULL)
    {
        
    }
    my_dog->name = name;
    my_dog->age = age;
    my_dog->owner = owner;
}