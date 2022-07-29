#include <iostream>
using namespace std;

class Animal {
public:
    Animal() { cout << "I am an animal" << endl; }
    int getSpeed() { return speed; }
protected:
    int speed;
};

class Cat : public Animal {
public:
    Cat() { speed = 30; cout << "I am a cat" << endl; }
};

class Dog : public Animal {
public:
    Dog() { speed = 20; cout << "I am a dog" << endl; }
};

class Giraffe : public Animal {
public:
    Giraffe() { speed = 37; cout << "I am a giraffe" << endl; }
};

int main()
{
    Cat cat;
    Dog dog;
    Giraffe giraffe;

    cout << "Dog runs " << dog.getSpeed() << "MPH" << endl;
    cout << "Cat runs " << cat.getSpeed() << "MPH" << endl;
    cout << "Giraffe runs " << giraffe.getSpeed() << "MPH" << endl;
}