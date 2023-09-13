#ifndef _4_SUM_H_
#define _4_SUM_H_
#define SUM(x, y) ((x) + (y))
#endif


struct Person
{
    char *name;
    char *email;
    int age;
};

int main(void)
{
    struct Person person;
    person.name = "Food Bar";
    person.email = "me@gmail.com";
    person.age = 7;
    return (0);
}