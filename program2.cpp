#include <iostream>
class shape
{
protected: // les variables protected vont etre accessible dans les sous classes de cette classe.
    double Largeur, Hauteur;

public: // creation du constructeur qui donne valeur au largeur et hauteur
    shape(double width, double height)
    {
        Largeur = width;
        Hauteur = height;
    }
};
class triangle : shape // classe herité du class shape
{
public:
    triangle(double width, double height) : shape(width, height) // creation du constructeur triangle avec parametres width et height qui sont deja definis dans le constructeur shape.
    {
    }
    double area()
    {
        return (Largeur * Hauteur); // la fonction retourne l'aire du triangle
    }
};
class rectangle : shape
{
public:
    rectangle(double width, double height) : shape(width, height) // c'est la meme que la sous class triangle
    {
    }
    double area()
    {
        return (Largeur * Hauteur);
    }
};

int main()
{
    triangle t = triangle(12, 23);   // creation de l'objet t de la sous classe triangle et donner des valeur au Largeur et Hauteur en utilisant le constructeur triangle.
    rectangle r = rectangle(15, 23); // creation de l'objet r de la sous classe rectangle et donner des valeur au Largeur et Hauteur en utilisant le constructeur rectangle.
    // appel au fontion area() et affichage des resultats
    std::cout << "the area of triangle is " << t.area() << std::endl;
    std::cout << "the area of rectangle is " << r.area() << std::endl;

    return 0;
}