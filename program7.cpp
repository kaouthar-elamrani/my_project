#include <iostream>
#include <cmath>
class vecteur3d
{
public:
    float X, Y, Z;
    vecteur3d()
    {
        X = Y = Z = 0;
    }

    vecteur3d(double x, double y, double z) // constructeur qui donne des au X , Y et Z.
    {
        X = x;
        Y = y;
        Z = z;
    }
    vecteur3d(vecteur3d &objet) // contructeur copies (ici il mets des valeurs pour objet 2 a partir du objet 1 )
    {
        X = objet.X;
        Y = objet.Y;
        Z = objet.Z;
    }
    void afficher() // affiche le vecteur
    {
        std::cout << "(" << X << "," << Y << ","
                  << Z
                  << ")" << std::endl;
    }
    vecteur3d somme(vecteur3d v) // add va retouner la somme des X dans premiere ligne ( add.X ) et des Y ( add.Y) et Z (add.Z)
                                 // add. return le resultat , X Y Z c'est pour le premier objet et c. est pour le 2eme objet .
    {
        vecteur3d add;
        add.X = X + v.X;
        add.Y = Y + v.Y;
        add.Z = Z + v.Z;
        return add;
    }
    vecteur3d produit(vecteur3d s)
    {
        vecteur3d scal;
        scal.X = X * s.X;
        scal.Y = Y * s.Y;
        scal.Z = Z * s.Z;
        return scal;
    }
    void coincide(vecteur3d c)
    {

        if (X == c.X && Y == c.Y && Z == c.Z) // si les 2 vecteurs objet ont meme x , y et z
            std::cout << "they are equal " << std::endl;
        else
            std::cout << "they are not equal " << std::endl;
    }
    double norme()
    {
        return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2)); // sqrt est definie dand la bibliotheque <cmath>
    }

    void normaux(vecteur3d c) // on compare les normes des vecteurs 1 et 2 et affciher le resulat
    {
        if (sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2)) > sqrt(pow(c.X, 2) + pow(c.Y, 2) + pow(c.Z, 2)))
            std::cout << "Le vecteur ayant la plus grande norm est :(" << X << "," << Y << "," << Z << ")" << std::endl;

        else
            std::cout << "Le vecteur ayant la plus grande norm est :(" << c.X << "," << c.Y << "," << c.Z << ")" << std::endl;
    }
};

int main()
{

    vecteur3d v;

    double x1, y1, z1, x2, y2, z2;
    // demander a l'utilisateur d'entrer les  x , y et z des vecteur 1 puis l'afficher puis le dexieme puis l'afficher
    std::cout << "Enter x1 ";
    std::cin >> x1;
    std::cout << "y1: ";
    std::cin >> y1;
    std::cout << "z1: ";
    std::cin >> z1;

    vecteur3d objet1(x1, y1, z1);
    objet1.afficher();

    std::cout << "Enter x2 ";
    std::cin >> x2;
    std::cout << "y2: ";
    std::cin >> y2;
    std::cout << "z2: ";
    std::cin >> z2;

    vecteur3d objet2(x2, y2, z2);
    objet1.afficher();
    // on fait appel au fonctions de la classe vecteur3d
    v = objet1.somme(objet2);
    std::cout << "vecteur resultant de l'addition : (" << v.X << "," << v.Y << "," << v.Z << ")" << std ::endl;

    v = objet1.produit(objet2);
    std::cout << "Le produit scalaire des deux vecteur est " << v.X + v.Y + v.Z << std::endl;

    objet1.coincide(objet2);

    vecteur3d n(2, 2, 2);
    std::cout << "la norme de vecteur n est : " << n.norme() << std::endl;
    objet1.normaux(objet2);

    return 0;
}