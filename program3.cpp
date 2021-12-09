#include <iostream>

class Complexe
{
public:
    double reel, imaginaire;
    Complexe() // creation du constructeur par defaut
    {
        reel = imaginaire = 0;
    }

    Complexe(double real, double imaginary) // constructeur qui donne des valeur au reel et imaginaire.
    {
        reel = real;
        imaginaire = imaginary;
    }

    Complexe(Complexe &objet) // contructeur copies (ici il mets des valeurs pour objet 2 a partir du objet 1 )
    {
        reel = objet.reel;
        imaginaire = objet.imaginaire;
    }
    void egalite(Complexe c) // ici on compare la partie reel du premier objet avec celle du 2eme objet et la partie imaginaire du premier objet avec celle du 2eme objet
    {
        if (reel == c.reel && imaginaire == c.imaginaire)
            std::cout << "The two complex numbers are equal" << std::endl;
        else
            std::cout << "The two complex numbers are not equal" << std::endl;
    }

    Complexe addition(Complexe c) // add va retouner la somme des reels dans premiere ligne ( add.reel ) et des imaginaires ( add.imaginaire )
    {                             // add. return le resultat , reel ou imaginaire c'est pour le premier objet et c. est pour le 2eme objet .
        Complexe add;
        add.reel = reel + c.reel;
        add.imaginaire = imaginaire + c.imaginaire;
        return add;
    }

    Complexe soustraction(Complexe c) // meme chose que l'addition mais ici on fait la soustraction
    {
        Complexe sou;
        sou.reel = reel - c.reel;
        sou.imaginaire = imaginaire - c.imaginaire;
        return sou;
    }

    Complexe multiplication(Complexe c) // ici multi retourne le resultat de la multiplication
    {
        Complexe multi;
        multi.reel = reel * c.reel - imaginaire * c.imaginaire;
        multi.imaginaire = reel * c.imaginaire - c.reel * imaginaire;
        return multi;
    }

    Complexe division(Complexe c)
    {
        Complexe div;
        div.reel = (reel * c.reel + imaginaire * c.imaginaire) / (c.reel * c.reel + c.imaginaire * c.imaginaire);
        div.imaginaire = (imaginaire * c.reel + reel * c.imaginaire) / (c.reel * c.reel + c.imaginaire * c.imaginaire);
        return div;
    }

    void afficher() // affichage du nombre complexe
    {
        std::cout << reel << "+" << imaginaire << "i" << std::endl;
    }
};

int main()
{ // declaration d'objet c et les variables
    Complexe c;
    double reel1, reel2, imaginaire1, imaginaire2;
    int n;

    std::cout << "Enter the Real  part of First Number: ";
    std::cin >> reel1;
    std::cout << "Enter the imaginary  part of First Number: ";
    std::cin >> imaginaire1;

    Complexe objet1(reel1, imaginaire1); // mettre les valeurs d'objet 1 avec le constructeur
    objet1.afficher();                   // l'afficher

    std::cout << "Enter the Real part of Second Number: ";
    std::cin >> reel2;
    std::cout << "Enter the Imaginary part of second number: ";
    std::cin >> imaginaire2;

    Complexe objet2(reel2, imaginaire2); // mettre les valeurs d'objet 2 avec le constructeur
    objet2.afficher();

    std::cout << "Choose the operation : " << std::endl; // afficher le menu pour que l'utilisateur choisi son choix
    std::cout << "1 : For Equality : " << std::endl;
    std::cout << "2 : For Addition : " << std::endl;
    std::cout << "3 : For Substraction : " << std::endl;
    std::cout << "4 : For Multplication : " << std::endl;
    std::cout << "5 : For Division : " << std::endl;
    std::cin >> n;

    switch (n) // le menu
    {
    case 1:
        objet1.egalite(objet2);
        break;
    case 2:
        c = objet1.addition(objet2);
        std::cout << "Addition is : (" << c.reel << ")+(" << c.imaginaire << ")i";
        break;
    case 3:
        c = objet1.soustraction(objet2);
        std::cout << "Subtraction is : (" << c.reel << ")+(" << c.imaginaire << ")i";
        break;
    case 4:
        c = objet1.multiplication(objet2);
        std::cout << "Multiplication is : (" << c.reel << ")+(" << c.imaginaire << ")i";
        break;
    case 5:
        c = objet1.division(objet2);
        std::cout << "Division result  is : (" << c.reel << ")+(" << c.imaginaire << ")i";
        break;
    default:
        std::cout << "Enter a valid number .";
        break;
    }

    return 0;
}