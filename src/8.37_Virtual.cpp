#include <stdio.h>

using namespace std;

// Abstrass class because has at least one virtual method
class Animal
{
public:

    // Notation that means that's no implementation
    virtual void speak()
    {
        printf("Animal don't speak!\n");
    }
    virtual void run()
    {
        printf("Animal don't run!\n");
    }
};

class Dog : public Animal
{
public:
    virtual void speak()
    {
        printf("Woof!\n");
    }
};

class Labrador : public Dog
{
public:
    virtual void run()
    {
        printf("Labrador running\n");
    }
};

int main()
{

    Labrador lab;
    lab.run();
    lab.speak();

    Animal * animals[5];
    animals[0] = &lab;
    animals[0]->speak();

    return 0;
}