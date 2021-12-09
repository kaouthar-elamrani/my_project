#include <iostream>

class MyClass
{
public:
    MyClass();  // Construteur
    ~MyClass(); // destructeur
};
// definition des constructeur et destructeur en dehors de la classe.

MyClass::MyClass()
{
    std::cout << "Hey I'm the constractor" << '\n';
}

MyClass::~MyClass()
{
    std::cout << "Hey I'm the destractor" << '\n';
}

int main()
{
    MyClass object; // creation de l'objet
    return 0;
}