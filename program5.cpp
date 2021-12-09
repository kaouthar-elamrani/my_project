#include <iostream>
using std::string;
class Animal
{
protected:
    string Nom;
    int Age;

public:
    void set_value(string name, int age) // la fonction met des valeurs aux nom et age
    {
        Nom = name;
        Age = age;
    }
    Animal() // constructeur par defaut
    {
    }
};
class Zebra : public Animal // public sert a rendre la classe animal une base accessible de la classe Zebra alors cette derniere peut utiliser les methodes de la classe mere
{
public:
    string Lorigine;
    Zebra(string origin) // constructeur met valeur au variable Lorigin
    {
        Lorigine = origin;
    }
    void IntroduceUrselfZebra() // methode qui affiche les resultats
    {
        std::cout << " Hey I'm " << Nom << " and I'm " << Age << " years old "
                  << " and I live in the " << Lorigine << std::endl;
    }
};
class Dolphin : public Animal // la meme que la classe Zebra
{
public:
    string Lorigine;
    Dolphin(string origin)
    {
        Lorigine = origin;
    }
    void IntroduceUrselfDolphin()
    {
        std::cout << " Hey I'm " << Nom << " and I'm " << Age << " years old "
                  << " and I live in the " << Lorigine << std::endl;
    }
};
int main()
{
    Zebra Z = Zebra("Jungle");    // creation d'objet Z et donner une valeur au Lorigin avec le constructeur Zebra
    Dolphin D = Dolphin("Ocean"); // creation d'objet D et donner une valeur au Lorigin avec le constructeur Dolphin
    Z.set_value("Ponny", 10);     // mettre des valeur au Z avec la methode set_value()
    Z.IntroduceUrselfZebra();     // appel au fonction qui affiche le resultat
    D.set_value("Dummy", 5);      // mettre des valeur au D avec la methode set_value()
    D.IntroduceUrselfDolphin();   // appel au fonction qui affiche le resultat

    return 0;
}