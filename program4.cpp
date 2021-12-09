#include <iostream>
class Mere // la classe mere
{
public:
    void display() // la methode display()
    {

        std::cout << "Hey I'm the mother class" << std::endl;
    }
};
class Fille : Mere
{
public:
    void display() // methode display() redefinie dans la sous classe fille.
    {

        std::cout << "Hey I'm the daughter class" << std::endl;
    }
};

int main()
{

    Mere M;      // objet de la classe mere
    Fille F;     // objet de classe fille
    M.display(); // appel a la fonction display() par l'objet M
    F.display(); // appel a la fonction display() par l'objet F

    return 0;
}