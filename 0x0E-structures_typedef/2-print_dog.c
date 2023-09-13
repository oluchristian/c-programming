#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
void print_dog(struct dog *d);
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    print_dog(&my_dog);
    return (0);
}
/**
 *print_dog - prints a struct dog
 *@d: instance of struct dog
 */
void print_dog(struct dog *d)
{
if (d == NULL)
return;
    printf("Name: %s\n", d->name ? d->name : "(nil)");
    printf("Age: %.1f\n", d->age);
    printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
